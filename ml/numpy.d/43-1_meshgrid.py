import numpy as np

def meshgrid():
    """demo numpy meshgrid"""
    points = np.arange(-5, 5, 1)
    xs, ys = np.meshgrid(points, points)
    print(xs)
    print("=" * 10)
    print(ys)

if __name__ == '__main__':
    print("=" * 10, meshgrid.__doc__, "=" * 10)
    meshgrid()