# so_long

A 2D game built with MiniLibX.

## 🛠️ Compilation

Use `make` to compile the project and MiniLibX.  

> **MiniLibX Source:** [42 Paris MiniLibX (Linux)](https://github.com/42paris/minilibx-linux.git)

## 🎮 Usage

Run the game with:  

```sh
./so_long map.ber
```

## 🗺️ Map Requirements

The map file (`.ber`) must follow these rules:  

- **Rectangular shape**  
- Contains at least:
  - 1 **starting point** (`P`)
  - 1 **exit** (`E`)
  - 1 **collectible** (`C`)
- Enclosed by **walls** (`1`)  
- **Empty spaces** are represented by (`0`)  

### Example:
```
111111
1P0C01
101E11
111111
```

## 🎨 Textures & Sprites

- **Player:** 4 directional frames  
- **Format:** All textures are `.xpm` files  

### 🔹 Assets Used:

| Element          | Source |
|-----------------|--------|
| **Water (Walls)** | [Ninjikin](https://ninjikin.itch.io/water) |
| **Ground** | [OpenGameArt](https://opengameart.org/content/tileable-brick-ground-textures-set-2) |
| **Car (Player)** | [Minzinn](https://minzinn.itch.io/pixelvehicles) |
| **Collectibles, Start, Exit** | *Hand-drawn* 🎨 |

---

### About
This is a project from 42 Common Core

I used the flood_fill algorithm to check the map

Enjoy the game! 🚗💨 
