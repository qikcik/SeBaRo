import imgui


class ModeWindow:
    def __init__(self):

        self.pid = False

    def update(self, dt):
        imgui.begin("Mode Select", True)
        (clicked, self.pid) = imgui.checkbox("Enabled Pid", self.pid)
        imgui.end()

        if clicked:
            return "ENABLE_PID "+str(int(self.pid))+" \n"
        return ""
