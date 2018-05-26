
import pandas as pd
import numpy as np

def line(val=""):
    print("-" * 50, val)

s1 = pd.Series([1,2, np.nan, 44, 1])
print(type(s1))
print(s1)
print(s1 * 3)
print(3 * s1)

line()

s2 = pd.Series(['4 cups', '1 cpu', '2 large', '1 can'], index=['Flour', 'Milk', 'Eggs', 'Spam'])
print(s2)

line()

q1_df = pd.DataFrame({'Apples': [30], 'Bananas':[21]})
print(q1_df)

line()

q1_df = pd.DataFrame({'Apples': [30, 41], 'Bananas':[21, 34]}, index=['2017 Sales', '2018 Sales'])
print(q1_df)

line()

q2_df = pd.DataFrame([[30, 21, 550], [41, 34, 990], [30,5,3]], index=['2016 Sales', '2017 Sales', '2018 Sales'], columns=['Apples', 'Bananas', 'Rices'])
print(q2_df)

line()
df = q2_df[['Apples', "Bananas"]]
print(type(df))
df = q2_df[['Apples']]
print(type(df))
print(df)
line()
se = q2_df['Apples']
print(type(se)) # series
print(se)
line()

print(q2_df[0:2])

line()

df = q2_df['Apples']
print(type(df))
print(df)
line()
print(df + 1)

line()

df = q2_df['Apples'].values
print(type(df))
print(df)

line("=> df.apply")

def add_3k(x):
    print(type(x))
    return x + 3000

print(q2_df)
s0 = q2_df.apply(sum, axis=0)
print("sum 0 ==>\n", s0)

s1 = q2_df.apply(sum, axis=1)
print("sum 1 ==>\n", s1)

a3k = q2_df.apply(add_3k)
print("add3k ==>\n", a3k)

line()

print(q2_df)

g_state = q2_df.groupby(['Apples'])
print(type(g_state))
print(g_state.size())

print("g_state.get_group(30)", g_state.get_group(30)) # get value in that group.
print("g_state.sum()\n", g_state.sum()) # for numerical data


