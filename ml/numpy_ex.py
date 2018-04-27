import numpy as np

def line(msg=""):
    print("=" * 20, msg, "=" * 20)

ar = np.array([1,2,3])
print(ar)
print(2 * ar)
print(ar * 2)
print("ndim", ar.ndim)
print("shape", ar.shape)
print("dtyoe", ar.dtype)

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


# Boolean Indexing
# Fancy Indexing

line()


line()
