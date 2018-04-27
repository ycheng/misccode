
import pandas as pd
import numpy as np

def line():
    print("-" * 50)

s2 = pd.Series(['4 cups', '1 cpu', '2 large', '1 can'], index=['Flour', 'Milk', 'Eggs', 'Spam'])
print(s2)

line()

q1_df = pd.DataFrame({'Apples': [30], 'Bananas':[21]})
print(q1_df)

line()

q1_df = pd.DataFrame({'Apples': [30, 41], 'Bananas':[21, 34]}, index=['2017 Sales', '2018 Sales'])
print(q1_df)

line()

q2_df = pd.DataFrame([[30, 21], [41, 34]], index=['2017 Sales', '2018 Sales'], columns=['Apples', 'Bananas'])
print(q2_df)
