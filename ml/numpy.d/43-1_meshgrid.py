import numpy as np
import matplotlib.pyplot as plt

def meshgrid():
    """demo numpy meshgrid"""
    points = np.arange(-5, 5, 1)
    xs, ys = np.meshgrid(points, points)
    print(xs)
    print("=" * 10)
    print(ys)

def meshgrid_plot():
    """demo numpy meshgrid and matplotlib"""
    points = np.arange(-5, 5, 0.01)
    xs, ys = np.meshgrid(points, points)
    z = np.sqrt(xs ** 2 + ys ** 2)
    plt.imshow(z, cmap=plt.cm.gray); plt.colorbar()
    plt.title("Image plot of $\sqrt{x^2 + y^2}$ for a grid of values")
    plt.show()

if __name__ == '__main__':
    print("=" * 10, meshgrid.__doc__, "=" * 10)
    # meshgrid()
    meshgrid_plot()
