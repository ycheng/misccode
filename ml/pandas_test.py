
import pandas as pd

names = ['Bob', 'Jessica']
birth = [1933, 2333]

BabyDataSet = [ (names[i], birth[i]) for i in range(len(names))]
print(BabyDataSet)

# same as above
BabyDataSet = list(zip(names, birth))
print(BabyDataSet)
# BabyDataSet = [names, birth] # wrong

df = pd.DataFrame(BabyDataSet, columns = ['Names', 'Births'])
print(df)

