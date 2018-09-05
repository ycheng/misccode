
# coding: utf-8

# In[1]:


import tensorflow as tf
import time

print("tf version = ", tf.__version__)

# with tf.device('/cpu:0'):
with tf.device('/gpu:0'):
 a = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[2, 3], name='a')
 b = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[3, 2], name='b')
 c = tf.matmul(a, b)

with tf.Session() as sess:
 print (sess.run(c))

while True:
    time.sleep(5000)
