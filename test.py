import pandas as pd
import os

df = pd.read_csv('pp.csv')
# print(df['Topic:'])
# print(df['Problem: '])

# res = []
# [res.append(x) for x in df['Topic:'] if x not in res]
# for folder_name in res:
#     os.mkdir(str(folder_name))

# print(res[0])

# path = str(res[1]) + '/myfile.txt'
# print(path)

# with open(path, 'w') as fp:
#     pass

for folder_name, file_name in zip(df['Topic:'], df['Problem: ']):
    try:
        path = str(folder_name) + "/" + str(file_name) + ".cpp"
        # print(path)
        with open(path, 'w') as fp:
            pass
    except:
        print(file_name)    

    

    