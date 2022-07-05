import pandas as pd
data = pd.read_csv('hp.csv', header=None)
data.rename(columns={0: 'who'}, inplace=True)
my_number = 148
for rank in range(1, 11):
    for i in data.where(data[rank] == my_number)['who']:
        if i > 0 and i < 200:
            print(rank, int(i), sep='\t')
