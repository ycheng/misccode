#%%
# import matplotlib.pyplot as plt
# import numpy as np
from sklearn import datasets
import pandas as pd
iris = datasets.load_iris() #use dataset offerd by sklearn

iris_DF = pd.DataFrame(iris.data, columns=iris.feature_names)
# print(iris_DF.head())

species = "species"
iris_DF[species] = "temp"
iris_DF.loc[:49, species] = "setosa"
iris_DF.loc[50:99, species] = "versicolor"
iris_DF.loc[100:149, species] = "verginca"

print("=" * 20, "head()")
print(iris_DF.head())
print("-" * 50)
print(iris_DF[species].describe())
print("-" * 50)
print(iris_DF.loc[48:52])
print("-" * 50)
print(iris_DF.groupby(species).size())
print("-" * 50)
print(iris_DF.groupby(species).describe())
print("-" * 50)
