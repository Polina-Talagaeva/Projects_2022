#!/usr/bin/env python
# coding: utf-8

# In[280]:





# In[1]:


import pandas as pd
import numpy as nm
import matplotlib as mpt
import matplotlib.pyplot as plt


# In[11]:


data = pd.read_csv('pokedex.csv')


# In[148]:


data.head(20)


# In[172]:


data.shape


# In[160]:


data.describe(include = 'all')


# In[187]:


task_1 = ['attack', 'hp', 'defense']
mean = []
median = []
std = []
for element in task_1:
    mean.append(data[element].mean())
    median.append(data[element].median())
    std.append(data[element].std())
table = pd.DataFrame({'mean': mean, 'median': median, 'std': std}, index = ['attack', 'hp', 'defense'])
table


# In[7]:


data[['attack', 'hp', 'defense']].mean()


# In[8]:


data[['attack', 'hp', 'defense']].median()


# In[12]:


data[['attack', 'hp', 'defense']].std()


# In[206]:


HP = data[['hp', 'type']].groupby(['type']).median()
HP


# In[282]:


HP.plot.bar(title = 'Dependence of Type', ylabel = 'HP amount', figsize = (10,5), color = '#2E8B57')
plt.grid()


# In[237]:


plt.pie(data['is_legendary'].value_counts(), labels = ['regular', 'legendary'], radius = 1.25, colors = 'g' 'r', autopct='%1.1f%%')
plt.title('Which occurs mostly?')


# In[155]:


HP.plot.bar(figsize = (10, 5), color = '#FF1493')


# In[50]:


vis = data[['is_legendary', 'generation']].groupby(['generation']).mean()
vis


# In[51]:


vis.plot.bar(figsize = (10, 10), width = 0.7, color = "#FFFF00")


# In[133]:


HP_number = [60.0, 65.0, 75.0, 60.0, 76.0, 70.0, 65.0, 79.0, 59.0, 65.0, 72.5, 70.0, 70.0, 65.0, 68.0, 67.0, 60.0, 68.0]
Type_= ["bug", "dark", "dragon", "electric", "fairy", "fighting", "fire", "flying", "ghost", "grass", "ground", "ice", "normal", "poison", "psychic", "rock", "steel", "water"]
mpt.pie(HP_number, labels = Type_, radius = 2, autopct='%1.2f%%')
mpt.show() #распределение хп на типы


# In[120]:


vis = data[['is_legendary', 'generation']].groupby(['generation']).mean()
vis


# In[137]:


number = [0.033113, 0.060000, 0.074074, 0.121495, 0.083333,0.083333, 0.212500]
is_legendary = ['1', '2', '3', '4', '5', '6', '7']
mpt.pie(number, labels = is_legendary, radius = 2, autopct='%1.2f%%')
mpt.show() #в каком поколение какой процент легендарных


# In[290]:


#the relation of cars possession to the age 
plt.figure(figsize=(10, 5))
plt.title('')
plt.xlabel('speed')
plt.ylabel('type')
plt.scatter(y=data['type'], x=data['speed'])


# In[243]:


speed_ = data[['speed', 'type']].groupby(['type']).median()
speed_


# In[ ]:


t = speed_.sns.replot(data[])


# In[252]:


sns.scatterplot(data=data, x="generation", y="percentage_male", color = 'r')


# In[262]:


keys = ['hp','attack', 'defense','generation' ]
n = sns.pairplot(data[keys], hue = 'generation')


# In[294]:


plt.figure(figsize=(10, 5))
sns.boxplot(x = data['percentage_male'], y = data['generation'])


# In[268]:


HP = data[['hp', 'type']].groupby(['type']).median()
HP.plot.bar(figsize = (10,5), title = 'Dependence of Type', ylabel = 'HP amount', color = '#2E8B57')
plt.grid()


# In[273]:


vis = data[['is_legendary', 'generation']].groupby(['generation']).mean()
vis
number = [0.033113, 0.060000, 0.074074, 0.121495, 0.083333,0.083333, 0.212500]
is_legendary = ['1', '2', '3', '4', '5', '6', '7']
mpt.pie(number, labels = is_legendary, radius = 2, autopct='%1.2f%%')
mpt.show() #в каком поколение какой процент легендарных


# # Task 1

# - Output descriptive statistics of the dataset: mean, median, standard deviation.
# 
# Here you could see the usage of functions: 'mean', 'median', 'std' from pandas. The output is numerical for some characteristics: 'attack', 'defense', 'health points'

# In[276]:


table = pd.DataFrame({'mean': mean, 'median': median, 'std': std}, index = ['hp', 'defense', 'attack'])
table


# *I decided to make it easier for others to analyze the information, making a 'table' with the values above*

# # Task 2

# - Plot at least 3 numerical fields.

# Here you could see the dependence of some values. 
# In this task were used such libraries as: 'matplotlib.pyplot' and 'pandas'. 
# Some charts and plots are demonstrated below: 'bar chart',  'pie chart',   'scatter plot'.

# The graph above(task 2.1), represents the dependence of the type on the health points. The values of 'health points' were grouped by the 'median' deviation for each 'type' of pockemon, using the additional variable 'HP'. Making a plot.bar I've specified such parameters: title, label - for less complicated understanding, size - for chart to be convenienlty situated, color code was taken from the 'html color table'.

# The graph above(task 2.2), represents the dependence of the amount of belonging to the 'legendary type' pokemons on their 'generation'. The values of dependence were grouped by the 'mean' deviation, for each 'generation' of pockemon, using the additional variable 'GENERATION_'. The pie chart has set parameters such: 'labels'- names to the program the variable, regarding which, pie chart is made. Also, the pie chart has some additional parameters: radius - size of pie chart, autopct - the auotomatical count of the correlation in percents.

# The graph above(task 2.3), represents the dependence of the 'type' pokemons on their 'speed'. The bar chart has parameters: label(x and y) - names the 0x and 0y lines, title - names the bar chart, figsize - sets the size. 
# 
# From the 'plt.scatter': 'y = data[' ']' - sets the 0y line parameter, 'x = data[' ']' -  sets the 0x line parameter.

# # Task 3

# - Do at least 2 comparisons similar to the ones in the Titanic example. "What are the distributions of column A for different values of column B?"

# The box plot above compares the information of 'percent of male' creatures of pockemons to their 'generation', using the 'matplotlib.pyplot' - to set the size of the plot, and the 'seaborn' - to set the parameters dependence, such as in the task(2.3): x and y - set the 0x and 0y lines

# The pair plot above (task3.2), compares the information of 'attack', defense', and 'health points', to the 'generation' of the pockemon. Firstly, the key words were given with the variable 'names', then, using the 'seaborn' liblary with the 'pair plot' function the plot was made(data[names] - where variables are taken from, hue = 'genertion' -  parameter, regarding which, variables are compared). 

# In[ ]:




