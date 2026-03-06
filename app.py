import customtkinter as ctk
from tkinter import messagebox
import subprocess
import os
from PIL import Image

# Global Theme Settings
ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")

# Path to your compiled C logic
EXE_PATH = "./a.exe"

class TechNexusApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Tech-Nexus Dashboard")
        self.root.geometry("1150x750")
        self.root.configure(fg_color="#000000")
        
        # Data Storage
        self.search_history = []
        self.wishlist = []

        # 1. INTRO LOGO (Starting Big and Centered)
        self.logo_label = ctk.CTkLabel(self.root, text="Tech-Nexus", 
                                       font=("Roboto", 70, "bold"), text_color="#3a7ebf")
        self.logo_label.place(relx=0.5, rely=0.5, anchor="center")

        # 2. INTRO SELECTION BUTTONS (Hidden at Start)
        self.intro_frame = ctk.CTkFrame(self.root, fg_color="transparent")
        
        # Start Move Animation after 1.2 seconds
        self.root.after(1200, self.animate_logo)

    # ==========================================
    # ANIMATION & TRANSITION
    # ==========================================
    def animate_logo(self):
        curr_x, curr_y = 0.5, 0.5
        def move():
            nonlocal curr_x, curr_y
            if curr_x > 0.12: curr_x -= 0.02
            if curr_y > 0.08: curr_y -= 0.02
            self.logo_label.place(relx=curr_x, rely=curr_y, anchor="center")
            
            if curr_x > 0.12 or curr_y > 0.08:
                self.root.after(15, move)
            else:
                self.logo_label.configure(font=("Roboto", 28, "bold"))
                self.show_big_options()
        move()

    def show_big_options(self):
        self.intro_frame.place(relx=0.5, rely=0.5, anchor="center")
        ctk.CTkButton(self.intro_frame, text="💻 FIND A LAPTOP", font=("Roboto", 20, "bold"),
                      width=320, height=65, corner_radius=10,
                      command=lambda: self.enter_dashboard("laptop")).pack(pady=15)
        ctk.CTkButton(self.intro_frame, text="📱 FIND A PHONE", font=("Roboto", 20, "bold"),
                      width=320, height=65, corner_radius=10,
                      command=lambda: self.enter_dashboard("phone")).pack(pady=15)

    def enter_dashboard(self, category):
        self.intro_frame.place_forget()
        self.setup_main_ui()
        if category == "laptop": self.show_laptop_view()
        else: self.show_phone_view()

    def setup_main_ui(self):
        # 1. Load Background Image First
        try:
            bg_data = Image.open("bg.png")
            # Increase size slightly for better coverage on high-res screens
            self.bg_img = ctk.CTkImage(light_image=bg_data, dark_image=bg_data, size=(1300, 850))
            self.bg_label = ctk.CTkLabel(self.root, image=self.bg_img, text="")
            self.bg_label.place(x=0, y=0, relwidth=1, relheight=1)
            # This ensures the image stays behind everything else
            self.bg_label.lower() 
        except Exception as e:
            print(f"Background Error: {e}")

        # 2. Sidebar (Semi-transparent so the image shows through)
        # Using a tuple for fg_color adds a slight dark tint (30% opacity look)
        self.sidebar = ctk.CTkFrame(self.root, width=220, corner_radius=0, fg_color=("#1a1a1a", "#0a0a0a"))
        self.sidebar.place(x=0, y=100, relheight=0.9)
        
        self.add_nav("💻 Laptops", self.show_laptop_view)
        self.add_nav("📱 Phones", self.show_phone_view)
        self.add_nav("📜 History", self.show_history_view)
        self.add_nav("⭐ Wishlist", self.show_wishlist_view)
        ctk.CTkButton(self.sidebar, text="Exit", command=self.root.quit, fg_color="transparent", border_width=1).pack(side="bottom", pady=20)

        # 3. Workspace (MUST be transparent to see the image)
        self.workspace = ctk.CTkFrame(self.root, fg_color="transparent")
        self.workspace.place(relx=0.6, rely=0.55, anchor="center", relwidth=0.75, relheight=0.8)
        
        # 4. Input Area (Transparent)
        self.input_area = ctk.CTkFrame(self.workspace, fg_color="transparent")
        self.input_area.pack(fill="x", pady=(0, 20))
        
        # 5. Results Box (Keeping it slightly dark for text readability)
        self.results_box = ctk.CTkTextbox(self.workspace, font=("Consolas", 15), 
                                          fg_color=("#2b2b2b", "#121212"), 
                                          border_width=1, border_color="#1f538d")
        self.results_box.pack(fill="both", expand=True)

    def add_nav(self, txt, cmd):
        ctk.CTkButton(self.sidebar, text=txt, command=cmd, height=45).pack(pady=10, padx=20, fill="x")

    # ==========================================
    # C-LOGIC BRIDGE
    # ==========================================
    def run_c_logic(self, inputs):
        if not os.path.exists(EXE_PATH): return "Error: a.exe not found"
        full_input = "\n".join(inputs + ["3"]) + "\n"
        try:
            proc = subprocess.run([EXE_PATH], input=full_input, text=True, capture_output=True)
            raw = proc.stdout
            if "choice (0 for All):" in raw:
                return raw.split("choice (0 for All):")[-1].split("--- MAIN MENU ---")[0].strip()
            return raw
        except: return "Execution Error"

    # ==========================================
    # LAPTOP & PHONE VIEWS
    # ==========================================
    def show_laptop_view(self):
        self.clear_inputs()
        ctk.CTkLabel(self.input_area, text="LAPTOP SEARCH", font=("Roboto", 24, "bold"), text_color="#3a7ebf").pack()
        row = ctk.CTkFrame(self.input_area, fg_color="transparent")
        row.pack(pady=10)

        self.laptop_ranges = {"Select Budget": "0", "Under ₹40k": "40000", "₹40k-₹70k": "70000", "₹70k-₹1.2L": "120000", "Custom...": "CUSTOM"}
        self.l_budget_drop = ctk.CTkComboBox(row, values=list(self.laptop_ranges.keys()), command=self.toggle_l_custom, width=160)
        self.l_budget_drop.pack(side="left", padx=5)
        self.l_custom = ctk.CTkEntry(row, placeholder_text="₹", width=70)
        
        self.l_usage = ctk.CTkComboBox(row, values=["0-All", "1-Gaming", "2-Office", "3-Coding"], width=120)
        self.l_usage.pack(side="left", padx=5)
        self.l_brand = ctk.CTkComboBox(row, values=["0-All", "1-Asus", "2-HP", "3-Lenovo", "4-Dell"], width=120)
        self.l_brand.pack(side="left", padx=5)
        
        ctk.CTkButton(row, text="SEARCH", width=90, command=self.do_laptop_search).pack(side="left", padx=5)
        ctk.CTkButton(row, text="⭐ SAVE", fg_color="#27ae60", width=80, command=self.save_wishlist).pack(side="left", padx=5)

    def toggle_l_custom(self, choice):
        if choice == "Custom...": self.l_custom.pack(side="left", padx=2)
        else: self.l_custom.pack_forget()

    def do_laptop_search(self):
        b = self.l_custom.get() if self.l_budget_drop.get() == "Custom..." else self.laptop_ranges.get(self.l_budget_drop.get(), "0")
        res = self.run_c_logic(["1", b, self.l_usage.get()[0], self.l_brand.get()[0]])
        self.results_box.delete("1.0", "end")
        self.results_box.insert("end", f"=== LAPTOP RESULTS ===\n\n{res}")
        self.search_history.append(f"Laptop Search: {res[:50]}...")

    def show_phone_view(self):
        self.clear_inputs()
        ctk.CTkLabel(self.input_area, text="PHONE SEARCH", font=("Roboto", 24, "bold"), text_color="#3a7ebf").pack()
        row = ctk.CTkFrame(self.input_area, fg_color="transparent")
        row.pack(pady=10)

        self.phone_ranges = {"Select Budget": "0", "Under ₹15k": "15000", "₹15k-₹40k": "40000", "₹40k-₹80k": "80000", "Custom...": "CUSTOM"}
        self.p_budget_drop = ctk.CTkComboBox(row, values=list(self.phone_ranges.keys()), command=self.toggle_p_custom, width=160)
        self.p_budget_drop.pack(side="left", padx=5)
        self.p_custom = ctk.CTkEntry(row, placeholder_text="₹", width=70)
        
        self.p_usage = ctk.CTkComboBox(row, values=["0-All", "1-Camera", "2-Battery", "3-Speed"], width=120)
        self.p_usage.pack(side="left", padx=5)
        self.p_brand = ctk.CTkComboBox(row, values=["0-All", "1-Poco", "2-Samsung", "3-Apple", "4-Moto"], width=120)
        self.p_brand.pack(side="left", padx=5)
        
        ctk.CTkButton(row, text="SEARCH", width=90, command=self.do_phone_search).pack(side="left", padx=5)
        ctk.CTkButton(row, text="⭐ SAVE", fg_color="#27ae60", width=80, command=self.save_wishlist).pack(side="left", padx=5)

    def toggle_p_custom(self, choice):
        if choice == "Custom...": self.p_custom.pack(side="left", padx=2)
        else: self.p_custom.pack_forget()

    def do_phone_search(self):
        b = self.p_custom.get() if self.p_budget_drop.get() == "Custom..." else self.phone_ranges.get(self.p_budget_drop.get(), "0")
        res = self.run_c_logic(["2", b, self.p_usage.get()[0], "0", self.p_brand.get()[0]])
        self.results_box.delete("1.0", "end")
        self.results_box.insert("end", f"=== PHONE RESULTS ===\n\n{res}")
        self.search_history.append(f"Phone Search: {res[:50]}...")

    # ==========================================
    # WISHLIST & HISTORY
    # ==========================================
    def parse_results(self, text):
        """Groups devices with their full specs into a dictionary."""
        lines = text.split('\n')
        devices_dict = {}
        current_device_name = None
        current_specs = []

        for line in lines:
            line = line.strip()
            if not line or "===" in line or "choice" in line:
                continue
            
            # Identify a new device entry (starts with "1. Model Name")
            if "Model Name" in line:
                # If we were already tracking a device, save its full specs block
                if current_device_name and current_specs:
                    devices_dict[current_device_name] = "\n".join(current_specs)
                
                # Start a new device
                current_device_name = line.split("-")[-1].strip() # Extract just the name
                current_specs = [line] # Start a new specs list with the name line
            else:
                # Add specs to the current device
                if current_device_name:
                    current_specs.append(line)

        # Catch the last device in the list
        if current_device_name and current_specs:
            devices_dict[current_device_name] = "\n".join(current_specs)
            
        return devices_dict

    def save_wishlist(self):
        """Allows user to pick a name but saves the full spec block."""
        curr = self.results_box.get("1.0", "end").strip()
        if not curr or "RESULTS" not in curr:
            messagebox.showwarning("Empty", "No results found! Search first.")
            return
        
        # Get the dictionary of {Name: Full Specs}
        devices_data = self.parse_results(curr)
        device_names = list(devices_data.keys())

        if not device_names:
            messagebox.showwarning("Error", "Could not identify devices in results.")
            return

        save_win = ctk.CTkToplevel(self.root)
        save_win.title("Save to Wishlist")
        save_win.geometry("400x250")
        save_win.attributes("-topmost", True)
        
        ctk.CTkLabel(save_win, text="Select Device Name:", font=("Roboto", 14, "bold")).pack(pady=15)
        
        sel_var = ctk.StringVar(value=device_names[0])
        ctk.CTkComboBox(save_win, values=device_names, variable=sel_var, width=320).pack(pady=10)
        
        def confirm():
            chosen_name = sel_var.get()
            full_specs_block = devices_data[chosen_name] # Retrieve the full block
            
            if full_specs_block not in self.wishlist:
                self.wishlist.append(full_specs_block)
                messagebox.showinfo("Success", f"Saved {chosen_name} with all specs!")
            else:
                messagebox.showinfo("Info", "This device is already in your wishlist.")
            save_win.destroy()

        ctk.CTkButton(save_win, text="CONFIRM SAVE", fg_color="#27ae60", command=confirm).pack(pady=20)
        
        def confirm():
            if sel_var.get() not in self.wishlist: self.wishlist.append(sel_var.get())
            save_win.destroy()
        ctk.CTkButton(save_win, text="SAVE", command=confirm).pack(pady=10)

    def show_history_view(self):
        self.clear_inputs()
        ctk.CTkLabel(self.input_area, text="HISTORY", font=("Roboto", 24, "bold")).pack()
        self.results_box.delete("1.0", "end")
        self.results_box.insert("end", "\n---\n".join(self.search_history) if self.search_history else "No History.")

    def show_wishlist_view(self):
        self.clear_inputs()
        ctk.CTkLabel(self.input_area, text="WISHLIST", font=("Roboto", 24, "bold"), text_color="#f1c40f").pack()
        self.results_box.delete("1.0", "end")
        self.results_box.insert("end", "\n".join(self.wishlist) if self.wishlist else "Wishlist Empty.")

    def clear_inputs(self):
        for w in self.input_area.winfo_children(): w.destroy()

if __name__ == "__main__":
    root = ctk.CTk()
    app = TechNexusApp(root)
    root.mainloop()