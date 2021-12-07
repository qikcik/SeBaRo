import imgui
import Modules.dofWindow as Dof
import Modules.motorWindow as Motor
import Modules.pidWindow as Pid
import Modules.modeWindow as Mode
import Modules.offsetWindow as Offset
import connection

class GameLoop:
    def __init__(self):
        self.connection = connection.Connection()

        self.dofState = Dof.DofState()
        self.dofWin = Dof.DofWindow(self.dofState)

        self.motorWin = Motor.MotorWindow()
        self.pidWin = Pid.PidWindow()
        self.modeWin = Mode.ModeWindow()
        self.offsetWin = Offset.OffsetWindow()

    def update(self, dt):
        worlds = self.connection.read()
        if worlds:
            self.dofState.tryUpdate(worlds)

        send = ""
        send += self.dofWin.update(dt)
        send += self.motorWin.update(dt)
        send += self.pidWin.update(dt)
        send += self.modeWin.update(dt)
        send += self.offsetWin.update(dt)
        self.connection.send(send)