@Sofice

数据科学

常用的可以查找数据集的网站以及一些在计算机视觉常用的图像数据集：

1. **Kaggle 数据集**:每个数据集都是一个小型社区，用户可以在其中讨论数据、查找公共代码或在内核中创建自己的项目。包含各式各样的真实数据集。

2. **Amazon 数据集**：该数据源包含多个不同领域的数据集，如：公共交通、生态资源、卫星图像等。网页中也有一个搜索框来帮助用户寻找想要的数据集，还有所有数据集的描述和使用示例，这些数据集信息丰富且易于使用！

3. **UCI机器学习资源库**：来自加州大学信息与计算机科学学院的大型资源库，包含100多个数据集。用户可以找到单变量和多变量时间序列数据集，分类、回归或推荐系统的数据集。

4. **谷歌数据集搜索引擎**：这是一个可以按名称搜索数据集的工具箱。

5. **微软数据集**：2018年7月，微软与外部研究社区共同宣布推出“Microsoft Research Open Data”。它在云中包含一个数据存储库，用于促进全球研究社区之间的协作。它提供了一系列用于已发表研究的、经过处理的数据集。

6. **Awesome Public Datasets Collection**：Github 上的一个按“主题”组织的数据集，比如生物学、经济学、教育学等。大多数数据集都是免费的，但是在使用任何数据集之前，用户需要检查一下许可要求。

7. **计算机视觉数据集**：Visual Data包含一些可以用来构建计算机视觉(CV)模型的大型数据集。用户可以通过特定的CV主题查找特定的数据集，如语义分割、图像标题、图像生成，甚至可以通过解决方案(自动驾驶汽车数据集)查找特定的数据集。

8. **Scikit-Learn：**

   ```python
   from sklearn.datasets import load_iris
   data = load_iris()
   X = data.data
   Y = data.target
   ```

   

常用的部分图像数据集：

1. **Mnist**: 手写数字数据集，包含 60000 张训练集和 10000 张测试集。（但该数据集通常只是作为简单 demo 使用，如果要验证算法模型的性能，最好在更大数据集上进行测试，实验结果才有足够的可信度）
2. **Cifar**：分为 Cifar10 和 Cifar100。前者包含 60000 张图片，总共10个类别，每类 6000 张图片。后者是 100 个类别，每个类别 600 张图片。类别包括猫狗鸟等动物、飞机汽车船等交通工具。
3. **ImageNet**：应该是目前最大的开源图像数据集，包含 1500 万张图片，2.2 万个类别。
4. **LFW**：人脸数据集，包含13000+张图片和1680个不同的人。
5. **CelebA**：人脸数据集，包含大约 20w 张图片，总共 10177个不同的人，以及每张图片都有 5 个位置标注点，40 个属性信息



# 特征工程

特征工程是一个**表示和展现数据**的过程。特征工程的目的是去除原始数据中的杂质和冗余，设计更高效的特征以刻画求解的问题与预测模型之间的关系

**数据处理八股**

```python
import re

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
pd.set_option('max_columns', 100)
pd.set_option('max_rows', 100)
import seaborn as sns
from scipy.special import boxcox1p
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import train_test_split

def DataAnalysis(data):
    '''
    数据分析
    '''

def ProcessData(train_df, test_df):
    '''
    预处理
    '''
    # 离群值
    # 合并数据集
    # 删除部分影响小的变量
    # 缺失值
    # 均值填充
    # 检查有无缺失值
    
    return full_df, train_dfRow

def FeatureEncoding(full_df):
    '''
    特征编码
    '''

def FeatureConstruction(full_df):
    '''
    特征构建
    '''

def FeatureScaling(full_df):
    '''
    特征缩放
    '''    

def FeatureSelection(data):
    '''
    特征选择
    '''

def FeatureEngineering(train_df, test_df):
    '''
    特征工程
    '''
    DataAnalysis(train_df)
    full_df, train_dfRow = ProcessData(train_df, test_df)
    FeatureEncoding(full_df)
    FeatureConstruction(full_df)
    FeatureScaling(full_df)
    FeatureSelection(data)
    # 拆分
    train_df = full_df[:train_dfRow]
    test_df = full_df[train_dfRow:]
    test_df.drop('SalePrice', axis=1, inplace=True)
    return train_df, test_df

def TrainData(train_df):
    '''
    训练数据
    '''
    # 交叉验证
    # model
    # 网格搜索
    # 正确率
    return model

def Predict(model, test_df):
    '''
    预测数据
    '''
    #保存结果
    predDf.to_csv('housePrice/out.csv', index=False, header=False)
    

if __name__ == "__main__":
    ############ 1.读取数据
    train_df = pd.read_csv('housePrice/train.csv')
    test_df = pd.read_csv('housePrice/test.csv')
    ############ 2.特征工程
    train_df, test_df = FeatureEngineering(train_df, test_df)
    ############ 3.训练数据
    model = TrainData(train_df)
    ############ 4.预测数据
    Predict(model, test_df)
 
```

**数据分析**

```python
data = pandas.read_csv('data.csv', keep_default_na=False)
# 数据若干行
print(data.head(3))
# 数据基本统计
print(data.describe(include="all"))
# 展示数据有几类
print(data["Age"].unique())
print(data['label'].value_counts())

# 探索性可视化
# 1.数据分布直方图与密度曲线
sns.distplot(data['SalePrice'])
# 计算偏度峰度
print("Skewness: %f" % data['SalePrice'].skew())
print("Kurtosis: %f" % data['SalePrice'].kurt())
data['SalePrice'] = np.log(data['SalePrice'])
# 2.数据散点图，连续型数据，观察趋势，去除离群点
a = pd.concat([data['SalePrice'], data['GrLivArea']], axis=1)
a.plot.scatter(x='GrLivArea', y='SalePrice', ylim=(0,800000))
# 3.箱型图，离散型数据
b = pd.concat([data['SalePrice'], data['OverallQual']], axis=1)
fig = sns.boxplot(x='OverallQual', y='SalePrice', data=b)
# 4.特征相关性
corrmat = data.corr()
sns.heatmap(corrmat, square=True, cmap='Blues')
# 只展示其中最相关的10个特征
cols = corrmat.nlargest(10, 'SalePrice')['SalePrice'].index
cm = np.corrcoef(data[cols].values.T)
hm = sns.heatmap(cm, cbar=True, annot=True, square=True, fmt='.2f', annot_kws={'size':10}, 
                 xticklabels=cols.values, yticklabels=cols.values, cmap='Blues')
# 列表
print(corrmat['SalePrice'].sort_values(ascending =False))
```

**预处理**

```python
# 1.处理离群值，通过观察散点图和箱型图，直接删除
train_df.drop(train_df[(train_df['TotalBsmtSF']>6000) & (train_df['SalePrice']<200000)].index,inplace=True)
train_df.reset_index(drop=True, inplace=True)
# 2.合并数据集
train_dfRow = train_df.shape[0]
full_df = train_df.append(test_df, ignore_index=True)
# 删除部分影响小的变量
full_df.drop(['Utilities', 'RoofMatl'], axis=1, inplace=True)
# 3.处理缺失值值
missing_count = full_df.isnull().sum().sort_values(ascending=False)
missing_rate = (full_df.isnull().sum()/full_df.isnull().count()).sort_values(ascending=False)
missing_df = pd.concat([missing_count, missing_rate], axis=1, keys=['count', 'rate'])
print(missing_df[missing_df['rate']>0])
# 缺失80% 以上直接删除
full_df.drop(missing_df[missing_df['rate'] > 0.8].index, axis = 1, inplace=True)
# 某些数值变量有缺失值是因为没有这个属性
cols = ["FireplaceQu", "GarageQual"]
for col in cols:
    full_df[col] = full_df[col].fillna('None')
# 使用均值，中位数或众数填充
full_df[col] = full_df[col].fillna(full[col].mean())
full_df[col] = full_df[col].fillna(full[col].median())
full_df[col] = full_df[col].fillna(full[col].mode()[0])
# 检查有无缺失值
print(full_df.isnull().sum()[full_df.isnull().sum()>0])
```

**特征编码**

```python
# 离散化，一些特征其被表示成数值特征缺乏意义
full_df['YearRemodAdd'] = full_df['YearRemodAdd'].astype(str)
# 序号编码
def OrdinalEncoding(df):
    df['MSZoning'] = df['MSZoning'].map({'C':1, 'RM':2, 'RH':2, 'RL':3, 'FV':4})
# 标签编码
le = LabelEncoder()
train['QUEUE_TYPE'] = le.fit_transform(train['QUEUE_TYPE'].astype(str))
# one-hot编码（通常在紧接训练之前）
full_df = pd.get_dummies(full_df)
# 自定义columns名称
weekdaycols = ['weekday_' + str(i) for i in range(1,8)]
tmpdf = pd.get_dummies(df['weekday'].replace('null', np.nan))
tmpdf.columns = weekdaycols
df[weekdaycols] = tmpdf
# 改变类型
data['distance'] = data['Distance'].replace('null', -1).astype(int)
# 日期变为周几, eg. 20201104 -> 4
def getWeekday(row):
    if row == 'null':
        return row
    else:
        return date(int(row[0:4]), int(row[4:6]), int(row[6:8])).weekday() + 1
df['weekday'] = df['Date'].astype(str).apply(getWeekday)
# 周内还是周末
df['weekday_type'] = df['weekday'].apply(lambda x: 1 if x in [6,7] else 0)
```

**特征缩放**

```python
# 1.对数变换，解决右边有尾巴的偏度值
train_df[col] = np.log1p(train_df[col])
# 2.求偏度并进行boxcox变换
from scipy.special import boxcox1p
# 数据做一备份
full_fe = full_df.copy()
full_fe.drop(['SalePrice', 'Id'], axis=1, inplace=True)
# 对于偏度大于0.75的量进行boxcox变换
full_numeric = full_fe.select_dtypes(exclude='object')
skew = full_numeric.apply(lambda x: x.skew()).sort_values(ascending=False)
skew_features = skew[abs(skew) >= 0.75].index
for feat in skew_features:
    full_fe[feat] = boxcox1p(full_fe[feat], 0.15)
# 3.标准化
# [0,1]标准化
scaler = preprocessing.MinMaxScaler()
scaler.fit(data)
data = scaler.transform(data)
# 正态分布标准化
scaler = preprocessing.StandardScaler()
```







## 数据分析

使用统计函数和可视化图表，进行探索性数据特征分析

计算**偏度峰度**，找出**离群点**，找出**缺失值数量**，观察是否需要**编码**，是否需要**归一化正则化**

## 数据预处理

### 缺失值

**缺失值的处理方法**：

1. **直接使用含有缺失值的特征**：当仅有少量样本缺失该特征的时候可以尝试使用；

2. **删除含有缺失值的特征**：这个方法一般适用于大多数样本都缺少该特征（如缺失80%以上），且仅包含少量有效值是有效的；

3. **插值补全缺失值**：

   + **均值/中位数/众数补全**

     如果样本属性的距离是可度量的，则使用该属性有效值的平均值来补全

     如果样本属性的距离不可度量，则可以采用众数或者中位数来补全

   + **同类均值/中位数/众数补全**

     对样本进行分类后，根据同类其他样本该属性的均值补全缺失值

    + **固定值补全**

      利用固定的数值补全缺失的属性值

    + **建模预测**

      利用机器学习方法，将缺失属性作为预测目标进行预测——具体为将样本根据是否缺少该属性分为训练集和测试集，然后采用如回归、决策树等机器学习算法训练模型，再利用训练得到的模型预测测试集中样本的该属性的数值。这个方法根本的**缺陷**是**如果其他属性和缺失属性无关，则预测的结果毫无意义；但是若预测结果相当准确，则说明这个缺失属性没必要纳入数据集中**，一般的情况是介于两者之间。

    + **高维映射**

      将属性映射到高维空间，采用**独热码编码**，将包含 K 个离散取值范围的属性值扩展为 K+1 个属性值，若该属性值缺失，则扩展后的第 K+1 个属性值置为 1。 这种做法是最精确的做法，保留了所有的信息，也未添加任何额外信息，若预处理时把所有的变量都这样处理，会大大增加数据的维度。这样做的好处是**完整保留了原始数据的全部信息、不用考虑缺失值**；缺点是**计算量大大提升，且只有在样本量非常大的时候效果才好**。

    + **多重插补**

      多重插补认为待插补的值是随机的，实践上通常是估计出待插补的值，再加上不同的噪声，形成多组可选插补值，根据某种选择依据，选取最合适的插补值。

    + **压缩感知和矩阵补全**

      压缩感知通过**利用信号本身所具有的稀疏性，从部分观测样本中回复原信号**。压缩感知分为感知测量和重构恢复两个阶段：

      - 感知测量：此阶段对原始信号进行处理以获得稀疏样本表示。常用的手段是傅里叶变换、小波变换、字典学习、稀疏编码等
      - 重构恢复：此阶段基于稀疏性从少量观测中恢复原信号。这是**压缩感知的核心**矩阵补全可以查看知乎上的问题： https://www.zhihu.com/question/47716840

    + **手动补全**

      除了手动补全方法，其他插值补全方法只是将未知值补以我们的主观估计值，不一定完全符合客观事实。在许多情况下，根据对所在领域的理解，手动对缺失值进行插补的效果会更好。但这种方法需要对问题领域有很高的认识和理解，要求比较高，如果缺失数据较多，会比较费时费力。

    + **最近邻补全**

      寻找与该样本最接近的样本，使用其该属性数值来补全。

      


### 图片数据扩充

对于图片数据，最常遇到的问题就是训练数据不足的问题，导致的后果就是**模型过拟合问题**

过拟合的解决方法可以分为两类：

1. **基于模型的方法**：主要是采用降低过拟合风险的措施，如简化模型（从卷积神经网络变成逻辑回归算法）、添加约束项以缩小假设空间（如 L1、L2等正则化方法）、集成学习、Dropout方法（深度学习常用方法）等；

2. **基于数据的方法**：主要就是**数据扩充**(Data Augmentation)，即根据一些先验知识，在保持特点信息的前提下，对原始数据进行适当变换以达到扩充数据集的效果。具体做法有多种，在保持图像类别不变的前提下，可以对每张图片做如下变换处理：

   + 一定程度内的随机旋转、平移、缩放、裁剪、填充、左右翻转等，这些变换对应着同一个目标在不同角度的观察结果；

   + 对图像中的元素添加噪声扰动，如椒盐噪声、高斯白噪声等；

   + 颜色变换。比如在图像的 RGB 颜色空间进行主成分分析，得到 3 个主成分的特征向量`p1,p2,p3`以及对应的特征值`λ1,λ2,λ3`，然后在每个像素的 RGB 值上添加增量`[p1,p2,p3]*[a1λ1,a2λ2,a3λ3]`，其中`a1,a2,a3`都是均值为 0， 方差较小的高斯分布随机数

   + 改变图像的亮度、清晰度、对比度、锐度等

3. **生成对抗网络**

4. **迁移学习**：即借用在大数据集（如 ImageNet）上预训练好的模型，然后在自己的小数据集上进行微调

   

### 异常值

异常值是指样本中的个别值，其数值明显偏离其余的观测值

**异常值检测**

1. **简单统计**：比如利用`pandas`库的`describe()`方法观察数据的统计性描述，或者简单使用散点图也能观察到异常值的存在

2. **3∂原则**: 这个原则有个条件：**数据需要服从正态分布**。在 3∂ 原则下，异常值如超过 3 倍标准差，那么可以将其视为异常值

3. **箱型图**

   这种方法是利用箱型图的**四分位距（IQR）对异常值进行检测，也叫Tukey‘s test**

   ![img](E:/Programming/Github/md_note/MachineLearning/箱型图.jpg)

   四分位距(IQR)就是上四分位与下四分位的差值。而我们通过IQR的1.5倍为标准，规定：超过**上四分位+1.5倍IQR距离，或者下四分位-1.5倍IQR距离**的点为异常值。

   ```python
   # 使用了numpy的percentile方法
   Percentile = np.percentile(df['length'],[0,25,50,75,100])
   IQR = Percentile[3] - Percentile[1]
   UpLimit = Percentile[3]+ageIQR*1.5
   DownLimit = Percentile[1]-ageIQR*1.5
   # 使用seaborn的可视化方法boxplot
   f,ax=plt.subplots(figsize=(10,8))
   sns.boxplot(y='length',data=df,ax=ax)
   plt.show()
   ```

4. **基于模型预测**

5. **基于近邻度的离群点检测**

6. **基于密度的离群点检测**

7. **基于聚类的离群点检测**

8. **专门的离群点检测**：除了以上提及的方法，还有两个专门用于检测异常点的方法比较常用：`One Class SVM`和`Isolation Forest`

   

**异常值处理**

- **删除含有异常值的记录**：直接将含有异常值的记录删除；
- **视为缺失值**：将异常值视为缺失值，利用缺失值处理的方法进行处理；
- **平均值修正**：可用前后两个观测值的平均值修正该异常值；
- **不处理**：直接在具有异常值的数据集上进行数据挖掘；



**峰度（Kurtosis）**：描述某变量所有取值分布形态陡缓程度的统计量

Kurtosis=0 与正态分布的陡缓程度相同

Kurtosis>0 比正态分布的高峰更加陡峭——尖顶峰

Kurtosis<0 比正态分布的高峰来得平台——平顶峰

**偏度（Skewness）**：是描述某变量取值分布对称性的统计量

Skewness=0 分布形态与正态分布偏度相同

Skewness>0 正偏差数值较大，为正偏或右偏。长尾巴拖在右边

Skewness<0 负偏差数值较大，为负偏或左偏。长尾巴拖在左边



### 类别不平衡

分类任务中存在某个或者某些类别的样本数量远多于其他类别的样本数量

1. **扩充数据集**
2. **尝试其他评价指标**：一般分类任务最常使用的评价指标就是准确度了，但它在类别不平衡的分类任务中并不能反映实际情况。ROC 曲线常被用于评价一个二值分类器的优劣，而且对于正负样本分布变化的时候，ROC 曲线可以保持不变，即不受类别不平衡的影响
3. **对数据集进行重采样**
4. **尝试人工生成数据样本**
5. **尝试不同分类算法**：决策树往往在类别不均衡数据上表现不错
6. **尝试对模型进行惩罚**：对分类器的小类样本数据增加权值，降低大类样本的权值



## 特征编码

+ **序号编码(Ordinal Encoding)**

  序号编码一般用于**处理类别间具有大小关系**的数据

  比如成绩，可以分为高、中、低三个档次，并且存在“高>中>低”的大小关系，那么序号编码可以对这三个档次进行如下编码：高表示为 3，中表示为 2，低表示为 1，这样转换后依然保留了大小关系

+ **独热编码(One-hot Encoding)**

  独热编码是采用 N 位状态位来对 N 个可能的取值进行编码

  **优点：**

  - 能够处理**非数值属性**。比如血型、性别等
  - 一定程度上扩充了特征。
  - 编码后的向量是稀疏向量，只有一位是 1，其他都是 0，可以利用向量的稀疏来**节省存储空间**。
  - **能够处理缺失值**。当所有位都是 0，表示发生了缺失。此时可以采用处理缺失值提到的**高维映射**方法，用第 **N+1** 位来表示缺失值

  **缺点：**

  1. 使用**高维度特征**时：

  - KNN 算法中，高维空间下两点之间的距离很难得到有效的衡量；
  - 逻辑回归模型中，参数的数量会随着维度的增高而增加，导致模型复杂，出现过拟合问题；
  - 通常只有部分维度是对分类、预测有帮助，需要借助特征选择来降低维度。

  2. **决策树模型不推荐**对离散特征进行独热编码：

  - **产生样本切分不平衡问题，此时切分增益会非常小**。

  - **影响决策树的学习**。

    决策树依赖的是**数据的统计信息**，而独热编码之后的特征的表达能力较差

+ **二进制编码(Binary Encoding)**

  利用二进制对类别 ID 进行哈希映射，最终得到 0/1 特征向量，并且特征维度小于独热编码，更加节省存储空间

+ **二元化**

  特征二元化就是将数值型的属性转换为布尔型的属性。通常用于假设属性取值分布是伯努利分布的情形

+ **离散化**

  将连续的数值属性转换为离散的数值属性

  **一些特征其被表示成数值特征缺乏意义**，例如年份还有类别，这里将其转换为字符串，即类别型变量

  - 对于线性模型，通常使用“海量离散特征+简单模型”。

- - 优点：模型简单
    - 缺点：特征工程比较困难，但一旦有成功的经验就可以推广，并且可以很多人并行研究。

  - 对于非线性模型（比如深度学习），通常使用“少量连续特征+复杂模型”。

- - 优点：不需要复杂的特征工程
    - 缺点：模型复杂

  离散化的常用方法是**分桶**

  **逻辑回归模型**的特征输入，常常将连续特征离散化为一系列 0/1 的离散特征，优势有：

  - 离散化之后得到的稀疏向量，**内积乘法运算速度更快，计算结果方便存储**。
  - 离散化之后，模型不再拟合特征的具体值，而是拟合特征的某个概念，因此能够对抗数据的扰动，具有很强的鲁棒性。
  - 逻辑回归属于广义线性模型，表达能力受限，只能描述线性关系。特征离散化之后，相当于**引入了非线性，提升模型的表达能力，增强拟合能力**。



## 特征构建

特征构建是指**从原始数据中人工的构建新的特征**

需要花时间去观察原始数据，思考问题的潜在形式和数据结构

一般可以使用**混合属性或者组合属性**来创建新的特征，或是**分解或切分原有的特征**来创建新的特征



## 特征缩放

### 归一化

将特征（或者数据）都缩放到一个指定的大致相同的数值区间内

**归一化的两个原因：**

- 某些算法要求样本数据或特征的数值**具有零均值和单位方差**；
- 为了消除样本数据或者特征之间的**量纲影响，即消除数量级的影响**

**常用的两种归一化方法：**

+ **线性函数归一化(Min-Max Scaling)**：对原始数据进行线性变换，使得结果映射到`[0,1]`的范围，实现对原始数据的等比缩放
+ **零均值归一化(Z-Score Normalization)**：将原始数据映射到均值为 0，标准差为 1 的分布上

如果数据集分为训练集、验证集、测试集，那么**三个数据集都采用相同的归一化参数，数值都是通过训练集计算得到**，即上述两种方法中分别需要的数据最大值、最小值，方差和均值都是通过训练集计算得到（这个做法类似于深度学习中批归一化，BN的实现做法）

归一化不是万能的，实际应用中，**通过梯度下降法求解的模型是需要归一化的，这包括线性回归、逻辑回归、支持向量机、神经网络等模型**。但**决策树模型不需要**

### 正则化

将样本或者特征的某个范数（如 L1、L2 范数）缩放到单位 1

正则化的过程是针对**单个样本**的，对每个样本将它缩放到单位范数；归一化是针对**单个属性**的，需要用到所有样本在该属性上的值



## 特征提取

特征提取一般是在特征选择之前，它提取的对象是**原始数据**，目的就是自动地构建新的特征，**将原始数据转换为一组具有明显物理意义（比如 Gabor、几何特征、纹理特征）或者统计意义的特征**

### 降维

1. **PCA**(Principal Component Analysis，主成分分析)	

   特征值越大，方差越大，信息量也就越大

   PCA 是一种线性降维方法，这也是它的一个局限性

2. **LDA**(Linear Discriminant Analysis，线性判别分析)

   LDA 是一种有监督学习算法，相比较 PCA，它考虑到数据的类别信息

3. **ICA**(Independent Component Analysis，独立成分分析)

   PCA特征转换降维，提取的是**不相关**的部分，ICA独立成分分析，获得的是**相互独立**的属性。ICA算法本质寻找一个线性变换 `z = Wx`，使得 z 的**各个特征分量之间的独立性最大**。

   通常先采用 PCA 对数据进行降维，然后再用 ICA 来从多个维度分离出有用数据。PCA 是 ICA 的数据预处理方法



### 图像特征提取

1. **SIFT** 特征

   优点：

   + 具有旋转、尺度、平移、视角及亮度不变性，有利于对目标特征信息进行有效表达；

   + SIFT 特征对参数调整鲁棒性好，可以根据场景需要调整适宜的特征点数量进行特征描述，以便进行特征分析

   缺点：不借助硬件加速或者专门的图像处理器很难实现

2. **SURF** 特征

   SURF 特征是对 SIFT 算法的改进，降低了时间复杂度，并且提高了鲁棒性

3. **HOG** 特征

   方向梯度直方图(HOG)特征是 2005 年针对行人检测问题提出的直方图特征，它通过计算和统计图像局部区域的梯度方向直方图来实现特征描述

   HOG 特征提取步骤如下：

   1. **归一化处理**。先将图像转为灰度图像，再利用伽马校正实现。这一步骤是为了提高图像特征描述对光照及环境变化的鲁棒性，降低图像局部的阴影、局部曝光过多和纹理失真，尽可能抵制噪声干扰；
   2. **计算图像梯度**；
   3. **统计梯度方向**；
   4. **特征向量归一化**；为克服光照不均匀变化及前景与背景的对比差异，需要对块内的特征向量进行归一化处理。
   5. **生成特征向量**

4. **LBP** 特征

   局部二值模式（LBP）是一种描述图像局部纹理的特征算子，它具有旋转不变性和灰度不变性的优点

   LBP 特征通过对**窗口中心点与邻域点的关系进行比较**，重新编码形成新特征以消除对外界场景对图像的影响，因此一定程度上解决了**复杂场景下（光照变换）特征**描述问题	



### 文本特征提取

1. **词袋模型**

   将整段文本以词为单位切分开，然后每篇文章可以表示成一个长向量，向量的每一个维度代表一个单词出现的频率，而该维度的权重反映了该单词在原来文章中的重要程度

   通常采用 **TF-IDF** 计算权重： $TF-IDF(t, d) = TF(t,d) × IDF(t)$

   其中 TF(t, d) 表示单词 t 在文档 d 中出现的频率，IDF(t) 是逆文档频率，用来衡量单词 t 对表达语义所起的重要性：  $IDF(t)=log\frac{文章总数}{包含单词 t 的文章总数+1}   $             

2. **N-gram 模型**

   将连续出现的 n 个词 (n <= N) 组成的词组(N-gram)作为一个单独的特征放到向量表示中，构成了 N-gram 模型

   另外，同一个词可能会有多种词性变化，但却具有相同含义，所以实际应用中还会对单词进行**词干抽取**(Word Stemming)处理，即将不同词性的单词统一为同一词干的形式

3. **词嵌入模型**

   将每个词都映射成低维空间（通常 K=50~300 维）上的一个稠密向量（Dense Vector）

   常用的词嵌入模型是 **Word2Vec**，它是一种底层的神经网络模型，有两种网络结构，分别是 CBOW(Continues Bag of Words) 和 Skip-gram；CBOW 是根据**上下文出现的词语预测当前词**的生成概率；Skip-gram 是根据**当前词来预测上下文中各个词的生成概率**



## 特征选择

给定属性集后，其中某些属性可能对于学习来说很关键，但有些属性意义就不大；特征选择涉及到计算复杂度和模型性能之间的取舍

需要选取子集并评价子集的好坏

**子集搜索**（前向搜索）：

- 给定特征集合 A={A1,A2,…,Ad} ，首先将每个特征看作一个候选子集（即每个子集中只有一个元素），然后对这 d 个候选子集进行评价。

  假设 A2 最优，于是将 A2 作为第一轮的选定子集。

- 然后在上一轮的选定子集中加入一个特征，构成了包含两个特征的候选子集。

  假定 A2,A5 最优，且优于 A2 ，于是将 A2,A5 作为第二轮的选定子集。

- 直到本轮的最优的特征子集不如上一轮的最优的特征子集

**子集评价**

计算**信息增益**，信息增益越大，表明特征子集 A 包含的有助于分类的信息越多



最简单的特征选择方法是：**去掉取值变化小的特征**；假如某特征只有 0 和 1 的两种取值，并且所有输入样本中，95% 的样本的该特征取值都是 1 ，那就可以认为该特征作用不大



常见的特征选择方法分为以下三种，主要区别在于特征选择部分是否使用后续的学习器：

- **过滤式**(filter)：先对数据集进行特征选择，其过程与后续学习器无关，即设计一些统计量来过滤特征，并不考虑后续学习器问题
- **包裹式**(wrapper)：实际上就是一个分类器，它是将后续的学习器的性能作为特征子集的评价标准。
- **嵌入式**(embedding)：实际上是学习器自主选择特征



1. **过滤式选择**

   该方法**先对数据集进行特征选择，然后再训练学习器**，特征选择过程与后续学习器无关。

   + 优点：**计算时间上比较高效，而且对过拟合问题有较高的鲁棒性**；

   + 缺点：**倾向于选择冗余特征**，即没有考虑到特征之间的相关性。

2. **包裹式选择**

   包裹式特征选择**直接把最终将要使用的学习器的性能作为特征子集的评价原则**，其目的就是为给定学习器选择最有利于其性能、量身定做的特征子集

   - 优点：直接针对特定学习器进行优化，考虑到特征之间的关联性，因此**通常包裹式特征选择比过滤式特征选择能训练得到一个更好性能的学习器**
   - 缺点：由于特征选择过程需要多次训练学习器，故**计算开销要比过滤式特征选择要大得多**

3. ##### 嵌入式选择

   嵌入式特征选择是将特征选择与学习器训练过程融为一体，两者在同一个优化过程中完成的，即**学习器训练过程中自动进行了特征选择**

   常用的方法包括：

   - 利用正则化，如 $L_1, L_2$ 范数，主要应用于如线性回归、逻辑回归以及支持向量机(SVM)等算法；
   - 使用决策树思想，包括决策树、随机森林、Gradient Boosting 等





# Numpy

用于Python数值计算基础包

引用：`import numpy as np`

## ndarray多维数组对象

### 生成

| 函数名                | 描述                              |
| --------------------- | --------------------------------- |
| array                 | 将列表，元组，数组等转化为ndarray |
| arange                | 内建函数                          |
| ones                  | 全1,给定形状和数据类型            |
| ones_like             | 全1，给定数组生成一个形状一样的   |
| zeros，zeros_like     | 全0                               |
| empty，empty_like     | 空数组                            |
| full，full_like       | 指定数值                          |
| eye, identity         | 主对角线矩阵                      |
| reshape               | 改变数组维度                      |
| linspace(0, 1, 5)     | 均匀从0-1的5个数                  |
| random.random((3, 3)) | 随机0-1数3*3个                    |

### 属性

shape：数组每一维度数量

dtype：数据类型（每一个元素类型都相同）

ndim：维度

### 算术

带标量计算的算数操作，会把计算参数传递给数组的每一个元素。

不同尺寸的数组间操作会用到**广播特性**

### 索引

- 切片：

  得到一份视图而并非拷贝（拷贝要用`arr[5:8].copy()`）

  `arr[:, i:i+1]`得到第i列

  `arr[i]`得到第i行

  对切片赋值会对切出的所有元素赋值

- 布尔索引：

  ```python
  names = np.array(['Bob', 'Joe', 'Will', 'Bob', 'Will', 'Joe', 'Joe'])
  data = np.random.randn(7, 4)
  # 用布尔索引，产生布尔数组array([ True, False, False, True, False, False, False])
  data[names == 'Bob']
  # 非
  data[~(names == 'Bob')]
  # 或
  data[(names == 'Bob') | (names == 'Will')]
  ```

- 神器索引：**将数据复制到新数组**

  ```python
  arr = np.arange(32).reshape((8, 4))
  # 按顺序选取4，3，0，6行
  arr[[4, 3, 0, 6]]
  # 每一行再选取第二维度
  arr[[1, 5, 7, 2], [0, 3, 1, 2]]
  # 改变选取的新数组的每一行中元素的顺序
  arr[[1, 5, 7, 2]][:, [0, 3, 1, 2]]
  ```



## 通用函数

快速的逐元素数组函数

```python
# 平方
np.sqrt(arr)
# 返回小数，整数部分
remainder, whole_part = np.modf(arr)
```

### 一元函数

| 函数名                   | 描述                                                   |
| ------------------------ | ------------------------------------------------------ |
| abs, fabs                | 整数、浮点数绝对值                                     |
| sqrt, square             | 平方根，平方                                           |
| exp                      | exp x                                                  |
| log, log10, log2         | 以e,10,2为底的对数                                     |
| sign                     | 符号函数                                               |
| ceil, floor              | 向上、向下取整                                         |
| rint                     | 保留到整数，并保持dtype                                |
| modf                     | 返回小数、整数部分                                     |
| isnan, isinf             | 是否是NaN，是否是无限                                  |
| sin, cos, arcsin, arccos | 三角函数，反三角函数                                   |
| logical_not              | 按位取反                                               |
| tile                     | 重复增加数组                                           |
| argsort                  | 排序，返回从小到大的下标                               |
| linespace                | 产生线性序列                                           |
| squeeze                  | 从数组的形状中删除单维度条目，即把shape中为1的维度去掉 |

### 二元函数

| 函数名                                                    | 描述                                 |
| --------------------------------------------------------- | ------------------------------------ |
| add, subtract, multiply, divide(floor_divide)             | 加，减，乘，除（省略余数）           |
| power                                                     | 乘方                                 |
| maximum，fmax, minimum, fmin                              | 对应元素最大最小值，fmax,fmin忽略NaN |
| mod                                                       | 求模                                 |
| copysign                                                  | 复制符号值                           |
| greater, greater_equal, less,less_equal, equal, not_equal | \>,>=,<,<=,=,!=                      |
| logical_and, logical_or, logical_xor                      | &,\|,^                               |
| concatenate([x, y])                                       | 合并                                 |
| x1, x2, x3 = np.split(x, [3, 5])                          | 分裂                                 |



## 面向数组操作

### 条件逻辑

```python
# x if condition else y
result = np.where(cond, x, y)
# True就取第一个数组，False就取第二个数组
np.where([True, False], [1, 2], [3, 4])
# 将正值设为2，负值设为-2
np.where(arr > 0, 2, -2)
```

### 数学统计

```python
# 两种方法计算
arr.mean()
np.mean(arr)
# 纵向计算
arr.mean(axis=0)
# 横向计算
arr.mean(axis=1)
```

| 方法            | 描述               |
| --------------- | ------------------ |
| sum             | 和                 |
| mean            | 平均值             |
| std, var        | 标准差，方差       |
| min, max        | 最大值，最小值     |
| argmin, argmax  | 最大值最小值位置   |
| cumsum, cumprod | 累计和，累计积     |
| sort,argsort    | 排序，原始顺序下表 |

###  布尔值数组

```python
bools = np.array([False, False, True, False])
# 是否有True
bools.any()
# 是否全是True
bools.all()
# 按位
np.sum((inches > 0.5) & (inches < 1))
# 掩码
 x[x < 5]
```

### 集合操作

| 方法              | 描述                               |
| ----------------- | ---------------------------------- |
| unique(x)         | 唯一值，并排序                     |
| intersect1d(x, y) | 交集，并排序                       |
| union1d(x, y)     | 并集，并排序                       |
| in1d(x, y)        | x中元素是否包含在y，返回布尔值数组 |
| setdiff1d(x, y)   | 差集，在x中但不在y中               |
| setxor1d(x, y)    | 异或集，在并集但不属于交集的元素   |

## 存储

```python
# 存储
np.save('arrays', arr)
# 载入
np.load('arrays.npy')
```

## 线性代数

转置：`arr.T` 

numpy.linalg中的方法

| 方法  | 描述               |
| ----- | ------------------ |
| diag  | 返回对角元素       |
| dot   | 矩阵乘法           |
| trace | 对角元素和         |
| det   | 行列式             |
| eig   | 特征值，特征向量   |
| inv   | 逆矩阵             |
| solve | 求解Ax = b         |
| lstsq | Ax = b的最小二乘解 |



## 随机数

numpy.random

| 方法              | 描述                   |
| ----------------- | ---------------------- |
| seed，RandomState | 随机种子，只使用一次   |
| permutation       | 返回一个序列的随机排列 |
| shuffle           | 随机排列一个序列       |
| rand              | 0-1均匀分布（维度）    |
| randint           | 给定范围的均匀分布     |
| randn             | 均值0方差1的正态分布   |
| binomial          | 二项分布               |
| normal            | 正态（高斯）分布       |
| beta              | beta分布               |
| chisquare         | 卡方分布               |
| gamma             | 伽马分布               |
| uniform           | [0,1)均匀分布          |

## 结构化数组

```python
# 创建
data = np.zeros(4, dtype={'names':('name', 'age', 'weight'), 
                          'formats':('U10', 'i4', 'f8')})
# 导入
data['name'] = ['Alice', 'Bob', 'Cathy', 'Doug']
# 获取一个实例
data[0]
```



# Pandas

`import pandas as pd`

`from pandas import Series, DataFrame`

## Series

+ 特殊的字典，具有数据对齐特性，可切片

+ 属性：

  values：值

  index：索引

  name, index.name：名字


```python
# 生成序列（字典）
obj = pd.Series([4, 7, -5, 3])
obj2 = pd.Series([4, 7, -5, 3], index=['d', 'b', 'a', 'c'])
obj3 = pd.Series(sdata, index=states) #sdata是字典，index缺省时按键的字典序排序
# 索引访问
obj2[['c', 'a', 'd']]
# 运算
obj2 * 2
np.exp(obj2)
# 检测索引是否存在
'b' in obj2
# 值是否有效
obj4.isnull()
```



## DataFrame

指定行列的二维索引
+ 属性：

  index,columns：行，列索引标签

  values：返回二维ndarray

  index.name, columns.name：名字

```python
# 利用包含等长度Numpy数组列表或字典，可指定列或索引顺序
data = {'state': ['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada', 'Nevada'],
        'year': [2000, 2001, 2002, 2001, 2002, 2003],
        'pop': [1.5, 1.7, 3.6, 2.4, 2.9, 3.2]}
data = {'Nevada': {2001: 2.4, 2002: 2.9},
       'Ohio': {2000: 1.5, 2001: 1.7, 2002: 3.6}}
frame = pd.DataFrame(data, columns=['year', 'state', 'pop', 'debt'],
                      index=['one', 'two', 'three', 'four','five', 'six'])
# 访问，返回Series,视图
frame['state'];frame.values[1] # 按列
frame.loc['three'] # 按行
# 赋值
frame2['debt'] = 16.5
frame2['debt'] = np.arange(6.)
val = pd.Series([-1.2, -1.5, -1.7], index=['two', 'four', 'five'])
frame2['debt'] = val
# 删除列
del frame2['eastern']
# 转置
frame3.T
# 排序
data = data.sort_values(by=['x1', 'x2'])
# 重置索引
data = data.reset_index(drop=True)
# 聚合
data.groupby('x1')
```



## Index

索引对象

+ 无法修改

+ 可重复 

| 方法         | 描述                                         |
| ------------ | -------------------------------------------- |
| append       | 将额外的索引对象粘贴到原索引，生成一个新索引 |
| difference   | 差集                                         |
| intersection | 并集                                         |
| union,&      | 交集                                         |
| isin         | 表示每一个值是否在传值容器中的布尔数组       |
| delete       | 按索引位删除                                 |
| drop         | 按索引值删除                                 |
| insert       | 按位插入                                     |
| is_monotonic | 是否递增                                     |
| is_unique    | 是否唯一                                     |
| unique       | 返回唯一值序列                               |

  

## 基本功能

### 索引器

避免整数索引显式隐式的混乱

+ loc：显式
+ iloc：隐式

### 重建索引

```python
obj = obj.reindex(['a', 'b', 'c', 'd', 'e'])
frame.loc[['a', 'b', 'c', 'd'], states]
```

reindex参数

| 参数       | 描述                                                         |
| ---------- | ------------------------------------------------------------ |
| index      | 新建作为索引的序列                                           |
| method     | 插值方式；ffill向前填充，bfill向后填充                       |
| fill_value | 缺失数据时的替代值                                           |
| limit      | 填充时，所需填充的最大尺寸间隙（以元素数量）                 |
| tolerance  | 填充时，所需填充的不精确匹配下的最大尺寸间隙（以绝对数字距离） |
| level      | 匹配MultiIndex级别的简单索引                                 |
| copy       | True，索引相同时总是复制数据                                 |

### 轴向删除

```python
# series
obj.drop(['d', 'c'])
# dataframe,列删除
data.drop('two', axis=1)
#inplace=True删除原对象中值，真删除
obj.drop('c', inplace=True)
```

### 切片

```python
# series
obj = pd.Series(np.arange(4.), index=['a', 'b', 'c', 'd'])
# a 0.0
# b 1.0
# c 2.0
# d 3.0
obj['b'] # 即obj[1]
obj[2:4] # 即obj['b':'d']包括尾部
obj[obj < 2]
# dataframe
data = pd.DataFrame(np.arange(16).reshape((4, 4)),
                    index=['Ohio', 'Colorado', 'Utah', 'New York'],
                    columns=['one', 'two', 'three', 'four'])
# 先选择行，再选择列
# loc轴标签
data.loc['Colorado', ['two', 'three']]
data.loc[:'Utah', 'two']
# iloc整数标签
data.iloc[2]
data.iloc[[1, 2], [3, 0, 1]]
```

### 缺失值

isnull() ：创建一个布尔类型的掩码标签缺失值。 

notnull() ：与 isnull() 操作相反。 

dropna() ：返回一个剔除缺失值的数据。 可以axis选择行列

fillna() ：返回一个填充了缺失值的数据副本。

### 合并

```python
pd.concat([ser1, ser2])
pd.concat([df3, df4], axis='col')
```

| 参数                  | 说明             |
| --------------------- | ---------------- |
| verify_integrity=True | 捕捉错误         |
| ignore_index=True     | 创建新的整数索引 |
| keys=['x', 'y']       | 多级索引         |



# Mataplotlib

<img src="./DataScience/anatomy.png" style="zoom: 80%;" />









# Tensorflow

**计算图**：是包含节点和边的网络 

**运算操作对象**（Operation Object, OP）:张量（tensor）对象（常量、变量和占位符）

为了构建计算图，需要定义所有要执行的常量、变量和运算操作

TensorFlow 支持以下三种类型的张量：

1. **常量**：常量是其值不能改变的张量

   ```python
   t_1 = tf.constant([4,3,2])
   t_2 = tf.constant(1，shape=[11])
   ```

2. **变量**：当一个量在会话中的值需要更新时，使用变量来表示

   ```python
   t_a = tf.Variable(t_1)# 用常量初始化
   t_b = tf.Variable(t_a, name='b')# 用变量初始化
   initial_op = tf.global_variables_initializer()# 必须显式初始化所有的声明变量
   saver = tf.train.Saver()# 保存变量
   ```

3. **占位符**：用于将值输入 TensorFlow 图中。它们可以和  feed_dict  一起使用来输入数据。在训练神经网络时，它们通常用于提供新的训练样本。在会话中运行计算图时，可以为占位符赋值。这样在构建一个计算图时不需要真正地输入数据。需要注意的是，占位符不包含任何数据，因此不需要初始化它们

   ```python
   tf.placeholder(dtype,shape=None,name=None)
   ```
   



**屏蔽GPU加速**

```python
os.environ["CUDA_VISIBLE_DEVICES"]="-1"
```



## TensorBoard

```python
# 设定格式化模型名称，以时间戳作为标记
model_name = "模型名-卷积".format()
# 设定存储位置，每个模型不一样的路径
tensorboard = TensorBoard(log_dir='logs/{}'.format(model_name))     
TensorBoardcallback = keras.callbacks.TensorBoard(
    log_dir='logs/{}'.format(model_name),
    histogram_freq=1, batch_size=32,
    write_graph=True, write_grads=False, write_images=True,
    embeddings_freq=0, embeddings_layer_names=None,
    embeddings_metadata=None, embeddings_data=None, update_freq=500
)
model.fit(x_train, y_train, callbacks=[tensorboard])
```



## 常用公共函数

```python
# 对应元素加减乘除，平方，次方，开方，自增减
tf.add(a, b)
tf.subtract(a, b)
tf.multiply(a, b)
tf.divide(b, a)
tf.square(a)
tf.pow(a, 3)
tf.sqrt(a)
x.assign_add(delta_x)
x.assign_sub(delta_x)
# 运算
tf.reduce_min(x)
tf.reduce_max(x)
tf.reduce_mean(x)
tf.reduce_sum(x)
# 判断
c = tf.where(tf.greater(a, b), a, b)  # 若a>b，返回a对应位置的元素，否则返回b对应位置的元素
tf.equal(pred, y_test)
tf.greater(a, b)2
tf.less(a, b)
# 枚举循环
seq = ['one', 'two', 'three']
for i, element in enumerate(seq):
    print(i, element)
# 最值索引
tf.argmin(test, axis=0)
tf.argmax(test, axis=0)
# 矩阵乘
tf.matmul(a, b)
# 强制转换
tf.cast(x1, tf.int32)
# 特定数组
tf.zeros([2,3],tf.int32)
tf.ones_like(t_1)
tf.fill([2,3],10)#全为指定值
tf.linspace(start,stop,num)# 包括stop，num为个数
tf.range(start=0,limit,delta=1)# 不包括limit，delta为增量
# 随机数
tf.set_random_seed(54)
tf.random.normal([M,N], mean=0.0, stddev=1.0, seed)# 正态分布
tf.random.truncated_normal([M,N], mean=0.0, stddev=1.0, seed)# 截断式正态分布
tf.random.uniform([M,N], minval=0.0, maxval=1.0)# 均匀分布
tf.random_crop(t_1,[2,5],seed)# 随机切片
tf.random_shuffle(t_1)# 沿着第一维随机排列张量
# numpy与tensor转化
b=tf.convert_to_tensor(a,dtype=tf.int32)
b.numpy()
# 拼接
tf.concat([a,b],axis=0)
tf.stack([a,b], axis=0)# 增加新维度
```



## 数值计算

```python
# 特征标签绑定，batch为配合enumerate，一次循环一个batch
dataset = tf.data.Dataset.from_tensor_slices((features, labels)).batch(32)
# 梯度下降
x = tf.Variable(tf.constant(3.0))
with tf.GradientTape() as tape:
    loss = tf.pow(x, 2)
grad = tape.gradient(y, x)
x.assign_sub(grad)
# 多个参数梯度更新
variables = [w1, b1]
grads = tape.gradient(loss, variables)
w1.assign_sub(lr * grads[0])
b1.assign_sub(lr * grads[1])

# 将标签转化为独热编码，再由argmax得到原编号
labels = tf.constant([1, 0, 2])  
output = tf.one_hot(labels, depth=classes)#classes分类个数
labels = tf.argmax(output, axis=1)
# 去掉y中纬度1
tf.squeeze(y) 
# 使y_dim符合概率分布
tf.nn.softmax(y_dim) 
# 激活函数
tf.nn.sigmoid(x)
tf.math.tanh(x)
tf.nn.relu(x)
tf.nn.leaky_relu(x)
# 均方误差
loss_mse = tf.reduce_mean(tf.square(y_train - y))
# 交叉熵
tf.losses.categorical_crossentropy(y_, y)# y_标准，y预测
tf.nn.softmax_cross_entropy_with_logits(y_, y)# 集成softmax和交叉熵
# 正则化项
tf.nn.l2_loss(w1)
# 生成网格待预测特征
# xx在-3到3之间以步长为0.1，yy在-3到3之间以步长0.1,生成间隔数值点
xx, yy = np.mgrid[-3:3:.1, -3:3:.1]
# 将xx, yy拉直，并合并配对为二维张量，生成二维坐标点
grid = np.c_[xx.ravel(), yy.ravel()]
grid = tf.cast(grid, tf.float32)
```



## keras

**Embedding**

一种单词编码方法，以低维向量实现了编码，这种编码通过神经网络训练优化，能表达出单词的相关性

```python
tf.keras.layers.Embedding(词汇表大小，编码维度)
# 编码维度就是用几个数字表达一个单词
# 对1-100进行编码， [4] 编码为 [0.25, 0.1, 0.11]
tf.keras.layers.Embedding(100, 3)

# 使x_train符合Embedding输入要求：[送入样本数， 循环核时间展开步数] ，
# 此处整个数据集送入所以送入，送入样本数为len(x_train)；输入4个字母出结果，循环核时间展开步数为4。
x_train = np.reshape(x_train, (len(x_train), 4))
y_train = np.array(y_train)

model = tf.keras.Sequential([
    Embedding(26, 2),
    SimpleRNN(10),
    Dense(26, activation='softmax')
])
```



### 多层前馈神经网络

六步法

1. import
2. train,test
3. model = tf.keras.models.Sequential
4. model.compile
5. model.fit
6. model.summary

```python
# 1
import tensorflow as tf
from sklearn import datasets
import numpy as np

# 2
x_train = datasets.load_iris().data
y_train = datasets.load_iris().target

# 3
model = tf.keras.models.Sequential([网络结构])
# 网络结构
# 拉直层
tf.keras.layers.Flatten()
# 全连接层
# activation=relu,softmax,sigmoid,tanh
# kernel_regularizer=tf.keras.regularizers.l1(),tf.keras.regularizers.l2()
tf.keras.layers.Dense(神经元个数, activation='激活函数', kernel_regularizer=正则化)
# 卷积层
tf.keras.layers.Conv2D ()
# LSTM层
tf.keras.layers.LSTM()  

# 4
# optimizer='sgd' or tf.keras.optimizers.SGD(lr=0.1)
# loss='mse' or tf.keras.MeanSquaredError()
# metrics='accuracy'都是数值 or 'categorical_accuracy'都是独热码 or ''sparse_categorical_accuracy'y_是数值y是独热码
model.compile(optimizer=优化器, loss=损失函数, metrics=[数值和独热码])

# 5
model.fit(x_train, y_train, batch_size=32, epochs=500, validation_split=测试集比例, validation_freq=多少次epoch测试一次)
# 6
model.summary()
```

**自定义model**，代替Sequential

```python
from tensorflow.keras.layers import Dense
from tensorflow.keras import Model
class IrisModel(Model):
    # 定义网络结构块
    def __init__(self):
        super(IrisModel, self).__init__()
        self.d1 = Dense(3, activation='softmax', kernel_regularizer=tf.keras.regularizers.l2())
    # 调用网络结构块，实现前向传播
    def call(self, x):
        y = self.d1(x)
        return y

model = IrisModel()
```

**数据增强**

```python
x_train = x_train.reshape(x_train.shape[0], 28, 28, 1)  # 给数据增加一个维度,从(60000, 28, 28)reshape为(60000, 28, 28, 1)

image_gen_train = ImageDataGenerator(
    rescale=1. / 1.,  # 如为图像，分母为255时，可归至0～1
    rotation_range=45,  # 随机45度旋转
    width_shift_range=.15,  # 宽度偏移
    height_shift_range=.15,  # 高度偏移
    horizontal_flip=False,  # 水平翻转
    zoom_range=0.5  # 将图像随机缩放阈量50％
)
image_gen_train.fit(x_train)
model.fit(image_gen_train.flow(x_train, y_train, batch_size=32), epochs=5, validation_data=(x_test, y_test),
          validation_freq=1)
```

**断点续训**

```python
# 读取
checkpoint_save_path = ".\checkpoint\fashion.ckpt"	#先定义出存放模型的路径和文件名，“.ckpt”文件在生成时会同步生成索引表
if os.path.exists(checkpoint_save_path + '.index'):		#判断是否有索引表，就可以知道是否报存过模型
    model.load_weights(checkpoint_save_path)
# 保存
cp_callback = tf.keras.callbacks.ModelCheckpoint(filepath=checkpoint_save_path,		# 文件存储路径
                                                 save_weights_only=True,			# 是否只保留模型参数
                                                 save_best_only=True)				# 是否只保留模型最优参数

history = model.fit(x_train, y_train, batch_size=32, epochs=5, 						# 加入callbacks选项，记录到history中
					validation_data=(x_test, y_test), validation_freq=1,
                    callbacks=[cp_callback])
# acc/loss
acc = history.history['sparse_categorical_accuracy'] # 训练集准确率
val_acc = history.history['val_sparse_categorical_accuracy'] # 测试集准确率
loss = history.history['loss'] # 训练集loss
val_loss = history.history['val_loss'] # 测试集loss

```

**参数提取**

```python
# 设置print输出格式
np.set_printoptions(threshold=np.inf) # np.inf表示无限大
# 提取参数
print(model.trainable_variables)
file = open('.\weights.txt', 'w')
for v in model.trainable_variables:
	file.write(str(v.name) + '\n')
	file.write(str(v.shape) + '\n')
	file.write(str(v.numpy()) + '\n')
file.close()
```

**预测结果**

```python
# model = tf.keras.models.Sequential()
# model.load_weights(model_save_path)
# 预处理数据
# 预测
result = model.predict(x_predict)
pred = tf.argmax(result, axis=1)
```

**数据集**

```python
mnist = tf.keras.datasets.mnist
(x_train, y_train), (x_test, y_test) = mnist.load_data()
cifar10 = tf.keras.datasets.cifar10
```



### 卷积神经网络

```python
# 卷积主结构
model = tf.keras.models.Sequential([
	Conv2D(filters=6, kernel_size=(5, 5), padding='same'),	#卷积层
	BatchNormalization(),									#BN层	
	Activation('relu'),										#激活层
	MaxPool2D(pool_size=(2, 2), strides=2, padding='same'),	#池化层
	Dropout(0.2),											#dropout层
])
# 卷积层
tf.keras.layers.Conv2D (
	filters = 卷积核个数,
	kernel_size = 卷积核尺寸, 			#正方形写核长整数，或（核高h，核宽w）
	strides = 滑动步长,					#横纵向相同写步长整数，或(纵向步长h，横向步长w)，默认1
	padding = “same” or “valid”, 		#使用全零填充是“same”，不使用是“valid”（默认）
	activation = “ relu ” or “ sigmoid ” or “ tanh ” or “ softmax”等 , 		#如有BN此处不写
	input_shape = (高, 宽 , 通道数)		#输入特征图维度，可省略
)
# 批标准化
tf.keras.layers.BatchNormalization()
# 池化
tf.keras.layers.MaxPool2D(
	pool_size=池化核尺寸，	#正方形写核长整数，或（核高h，核宽w）
	strides=池化步长，		#步长整数， 或(纵向步长h，横向步长w)，默认为pool_size
	padding=‘valid’or‘same’ #使用全零填充是“same”，不使用是“valid”（默认）
)
tf.keras.layers.AveragePooling2D(
	pool_size=池化核尺寸，	#正方形写核长整数，或（核高h，核宽w）
	strides=池化步长，		#步长整数， 或(纵向步长h，横向步长w)，默认为pool_size
	padding=‘valid’or‘same’ #使用全零填充是“same”，不使用是“valid”（默认）
)
# 舍弃
tf.keras.layers.Dropout(舍弃的概率)
```



### 循环神经网络

```python
tf.keras.layers.SimpleRNN(记忆体个数，activation=‘激活函数’ ，return_sequences=是否每个时刻输出ht到下一层)
# 参数
	activation=‘激活函数’ （不写，默认使用tanh）
	return_sequences=True 各时间步输出ht
	return_sequences=False 仅最后时间步输出ht（默认）
# 例：
SimpleRNN(3, return_sequences=True)

# RNN要求输入数据（x_train）的维度是三维的[送入样本数，循环核时间展开步数，每个时间步输入特征个数]
# 此处整个数据集送入，送入样本数为len(x_train)；输入1个字母出结果，循环核时间展开步数为1; 表示为独热码有5个输入特征，每个时间步输入特征个数为5
x_train = np.reshape(x_train, (len(x_train), 1, 5))
y_train = np.array(y_train)

model = tf.keras.Sequential([
    SimpleRNN(3),
    Dense(5, activation='softmax')
])
```



































