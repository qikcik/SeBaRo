# -*- coding: utf-8 -*-

# Modified ImGUI example extended by:
# Author: Qikcik (Dominik Rudnik - dominikrudnik01@gmail.com)
# License: MIT

from __future__ import absolute_import

import pyglet
from pyglet import gl

import imgui
from imgui.integrations.pyglet import create_renderer

import gameLoop


def main():
    GameLoop = gameLoop.GameLoop()

    window = pyglet.window.Window(width=1280, height=720, resizable=True)
    gl.glClearColor(0.23, 0.23, 0.23, 0)
    imgui.create_context()
    impl = create_renderer(window)

    def update(dt):
        imgui.new_frame()
        if imgui.begin_main_menu_bar():
            if imgui.begin_menu("File", True):

                clicked_quit, selected_quit = imgui.menu_item(
                    "Quit", 'Cmd+Q', False, True
                )

                if clicked_quit:
                    exit(1)

                imgui.end_menu()
            imgui.end_main_menu_bar()

        GameLoop.update(dt)

    def draw(dt):
        update(dt)
        window.clear()
        imgui.render()
        impl.render(imgui.get_draw_data())

    pyglet.clock.schedule_interval(draw, 1 / 120.)
    pyglet.app.run()
    impl.shutdown()


if __name__ == "__main__":
    main()
