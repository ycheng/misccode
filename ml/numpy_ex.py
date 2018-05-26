import numpy as np

def line(msg=""):
    print("=" * 20, msg, "=" * 20)

ar = np.array([1,2,3])
print(ar)
print(2 * ar)
print(ar * 2)
print("ndim", ar.ndim)
print("shape", ar.shape)
print("dtype", ar.dtype)

print("np.zeros((2,3)):") # similar to np.empty()
print(np.zeros((2,3)))
print("np.arange(5):", np.arange(5))

print("np.array: copy input data")
print("np.asarray: copy if input is not np.array")
print("np.arange: build-in range, but return np.array")
print("np.ones / np.ones_like: all one array")
print("np.zero / np.zero_like: all zero array")
print("np.empty / np.empty_like: create but not fill")
print("np.full / np.full_like: fill value")
print("np.eye / np.identity: identity matrix")


# Boolean Indexing: TODO
# Fancy Indexing: always copy data into a new array.
arr = np.empty((8, 4))
for i in range(8):
    arr[i] = i
print(arr[[4, 3, 0, 6]])
print(arr[[-3, -5, -7]])

line()
arr = np.arange(32).reshape((8, 4))
o1 = arr[[1, 5, 7, 2], [0, 3, 1, 2]]
print(o1)

o2 = arr[[1, 5, 7, 2]][:, [0, 3, 1, 2]]
print(o2)

line("Transport, Matrix dot")

arr = np.arange(15).reshape((3,5))
print(arr)
print(arr.T)

print("Matrix dot")
print(np.dot(arr, arr.T))

print("Tendor transpose dot")
arr = np.arange(16).reshape((2, 2, 4))
# 2nd axis first, then first axis, finally last axis unchanged
t1 = arr.transpose((1, 0, 2))
print(t1)

line("swap axis")
arr = np.arange(16).reshape((2, 2, 4))
print(arr)
# swapaxes similarly returns a view on the data without making a copy.
sw = arr.swapaxes(1, 2)
print(sw)

# [ [1,4, 6]

line()


line()
