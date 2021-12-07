from array import array

import imgui


class DofState:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0
        self.plot_points = [0]

    def tryUpdate(self,worlds):
        if worlds[0] == "DOF_STATE":
            self.x = float(worlds[1])
            self.y = float(worlds[2])
            self.z = float(worlds[3])


class DofWindow:
    def __init__(self, state: DofState):
        self.state = state

    def update(self, dt):
        temp = 0
        imgui.begin("DOF sensor", True)
        (changed, temp) = imgui.input_float("gyroscope X", self.state.x)
        (changed, temp) = imgui.input_float("gyroscope Y", self.state.y)
        (changed, temp) = imgui.input_float("gyroscope Z", self.state.x)

        if len(self.state.plot_points) > 100:
            self.state.plot_points.pop(1)
        self.state.plot_points.append(self.state.y)
        imgui.plot_lines(
            "Plot gyr. Y",
            array("f", self.state.plot_points)
        )

        imgui.end()

        return ""
