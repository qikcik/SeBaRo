import imgui


class OffsetWindow:
    def __init__(self):
        self.z_offset = 2.565;

    def update(self, dt):
        temp = 0
        imgui.begin("Offset DOF", True)

        (changed1, self.z_offset) = imgui.input_float("Z_Offset", self.z_offset)
        resend = imgui.button("Re-send")
        imgui.end()

        if changed1 or resend:
            return "SET_OFFSET "+str(self.z_offset)+" \n"
        return ""
