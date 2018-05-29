#! /usr/bin/python3
#%%
import pandas as pd
d = {'col1': range(1,6),
    'col2': range(10, 60, 10)}
df = pd.DataFrame(data=d)

print(df.iloc[2:4, :1])
print("-" * 50)
print(df[:1]) # standard slice: include start, and end - 1
print("-" * 50)
print(df.loc[:1])
print("-" * 50)
df.loc[1:2, "col1"] = 10
print("-" * 50)
print(df)
print("-" * 50)
print(df[1:2])
print("-" * 50)
print(df.iloc[1:2])
