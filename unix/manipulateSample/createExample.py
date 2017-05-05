from tkinter import *
from tkinter import filedialog
from tkinter.scrolledtext import ScrolledText


root = Tk()
files = []
class App:
	def __init__(self, master):
		frame = Frame(master)
		frame.pack()
		self.button7 = Button(frame,text="Wow click me", command=self.all)
		self.button7.pack(side=LEFT)
	def all(self):
		output = "You clicked a button!!! ANOTHER TEXT BOX FOR YOU!!"
		

		for widget in root.winfo_children():
			widget.destroy()
		textPad = ScrolledText(root, width=50, height=40)
		textPad.insert(END, output)
		app = App(root)
		textPad.pack()





##w = Label(root, text="Hello Tkinter!")
#app = App(root)
#w.pack()

textPad = ScrolledText(root, width=50, height=40)
textPad.insert(END, "Input text example")
app = App(root)
textPad.pack()
root.mainloop()

root.mainloop()
