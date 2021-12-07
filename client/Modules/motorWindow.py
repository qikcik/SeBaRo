import imgui


class MotorWindow:
    def __init__(self):
        self.left = 0
        self.right = 0

    def update(self, dt):
        temp = 0
        imgui.begin("ControlMotor", True)
        (changedL, self.left) = imgui.input_int("Left", self.left)
        (changedR, self.right) = imgui.input_int("Right", self.right)
        resend = imgui.button("Re-send")
        imgui.end()

        if changedL or changedR or resend:
            return "SET_MOTOR "+str(self.left)+" "+str(self.right)+" \n"
        return ""
