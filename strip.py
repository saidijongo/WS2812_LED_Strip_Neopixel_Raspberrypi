import board
import neopixel
import time
import random

# Define the Neopixel strip
strip = neopixel.NeoPixel(board.D18, 30, brightness=1)

# Animation colors
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
white = (255, 255, 255)
cbr = (255,153,51)
colors = [red, green, blue,cbr]

def fill_color(color):
    for i in range(len(strip)):
        strip[i] = color
        strip.show()

def rainbow_animation(delay, cycles):
    for _ in range(cycles):
        for j in range(255):
            for i in range(len(strip)):
                strip[i] = wheel((i + j) & 255)
            strip.show()
            time.sleep(delay)

def wheel(pos):
    if pos < 85:
        return (pos * 3, 255 - pos * 3, 0)
    elif pos < 170:
        pos -= 85
        return (255 - pos * 3, 0, pos * 3)
    else:
        pos -= 170
        return (0, pos * 3, 255 - pos * 3)

def flash_colors(colors, delay, repetitions):
    for _ in range(repetitions):
        for color in colors:
            fill_color(color)
            time.sleep(delay)
        fill_color(white)
        time.sleep(delay)

def random_sparkles(sparkle_count, delay, duration):
    start_time = time.time()
    end_time = start_time + duration
    while time.time() < end_time:
        for _ in range(sparkle_count):
            pixel = random.randint(0, len(strip) - 1)
            color = random.choice(colors)
            strip[pixel] = color
        strip.show()
        time.sleep(delay)
        fill_color(white)

while True:
    rainbow_animation(0.01, 5)
    flash_colors([cbr,red, green, blue], 0.2, 3)
    random_sparkles(5, 0.05, 5)

