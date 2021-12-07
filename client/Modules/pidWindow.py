import imgui


class PidWindow:
    def __init__(self):
        self.p = 25
        self.i = 0
        self.d = 1.2

    def update(self, dt):
        temp = 0
        imgui.begin("Control Pid", True)

        (changed1, self.p) = imgui.input_float("P", self.p)
        (changed2, self.i) = imgui.input_float("I", self.i)
        (changed3, self.d) = imgui.input_float("D", self.d)
        resend = imgui.button("Re-send")
        imgui.end()

        if changed1 or changed2 or changed3 or resend:
            return "SET_PID "+str(self.p)+" "+str(self.i)+" "+str(self.d)+" \n"
        return ""
        return ""
