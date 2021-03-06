$K$为标签数，$d$为特征数，$K_i$为$X_i$的类别数，$N$为样本数，$D$为数据集，$D_c$为数据子集

# 判别式模型(Discriminative Model)

直接学习条件分布概率$P(Y|X)$

往往准确率更高，可简化问题



## 感知机(Perceptron)

**原始形式**

给定训练集$X,y\in\{-1,1\}$，感知机$sign(w·x+b)$学习的损失函数为$L(w,b)=-\sum_{x_i\in m}y_i(w·x_i+b)$

感知机算法是误分类驱动的，采用随机梯度下降法，每次选取一个误分类点对w,b进行更新：$w:=w+\eta y_ix_i，b:=b+\eta y_i$，$\eta\in(0,1]$称为学习率（步长），误分条件为：$y_i(w·x_i+b)\leqslant0$

**对偶形式**

令$\alpha_i=n_i\eta$，则误分条件为：$\large y_i(\sum_{j=1}^Na_jy_jx_j·x_i+b)\leqslant0$，更新：$\large \alpha_i:=\alpha_i+\eta，b:=b+\eta y_i$，结果求得 $\large w=\sum_{i=1}^N\alpha_iy_ix_i$，在求误分条件时所用内积可以先求出来存在矩阵中（**Gram矩阵**）：$G=[x_i·x_j]_{N\times N}$

可以证明感知机的原始和对偶形式都是收敛的

```python
from sklearn.linear_model import Perceptron
# 参数：正则化项penalty=None/l1/l2 正则化系数alpha 学习率eta0 最大迭代次数max_iter=5 终止阈值tol=None
perceptron = Perceptron()
perceptron.fit(X,y)
# 模型参数w，b和迭代次数
w = perceptron.coef_ 
b = perceptron.intercept_
it = perceptron.n_iter_
# 预测准确率
perceptron.score(X,y)
```

**当特征维度大时用对偶形式，当样本多时用原始形式**



## k邻近(k-Nearest Neighbor)

给定距离度量，选取最“近”的k个点，再根据给定分类决策规则，确定类别

非参数算法，最简单有效；但必须**保存全部数据集，使用大量存储空间**；对每个数据计算距离值，**耗时很大**；无法给出任何数据的基础结构信息，无法得到平均样本和典型样本的特征

**距离度量**

> 数学-聚类距离

**k值选择**

k值越小，近似误差越小，估计误差越大，模型更复杂，容易过拟合，一般使用交叉验证选取一个比较小的值

**分类决策规则**

多数表决规则等价于经验风险最小化

**KD-Tree**

对k维空间中的实例点进行存储以便对其进行快速检索的树形结构，是一种二叉树。依次选择坐标轴对空间切分，选择训练实例点在坐标轴上的中位点为切分点时，直到子区域没有实例，得到的kd树是平衡的，但搜索效率未必是最优的

搜索时，先找到目标点对应的叶子节点，对应划分点为最邻近点，为再向上一层一层回溯，找兄弟节点中是否有实例包含在超球体内，如有则更新最邻近点，时间复杂度为$O(logn)$



## 线性回归(Linear Regression)

简洁，高效，容易理解

特征（features）为自变量，标签（labels）为因变量



**数学推导**

给定一组数据，找出一种关系来预测标签：
$$
\large{
X=\begin{bmatrix}
x_{11}&x_{12}&...&x_{1d}&1\\
x_{21}&x_{22}&...&x_{2d}&1\\ 
...&...&...&...&1\\
x_{m1}&x_{m2}&...&x_{md}&1\\
\end{bmatrix}\\
y=(y_1,y_2,...,y_m)^T\\
广义参数\quad\hat{w}=(w_1,...,w_n;b)^T\\
y=X\hat{w}^T
}
$$
这里采用平方误差求最优$\hat{w}$： $\large E_\hat{w}=\sum_{i=1}^m(y_i-x_i^T\hat{w})^2$

对于上述式子$f(\hat{w})$可以通过梯度下降等方法得到最优解。但是使用矩阵表示将会使求解和程序更为简单：$\large E_\hat{w}=(y-X\hat{w})^T(y-X\hat{w})$

将$f(\hat{w})$对$\hat{w}$求导可得：$\large \cfrac{\partial E_\hat{w}}{\partial \hat{w}}=2X^T(X\hat{w}-y)$

当$X^TX$为满秩矩阵或正定矩阵时，使上式等于0，便可得到：$\large \hat{w}=(X^TX)^{-1}X^Ty$，即非线性最小二乘问题的高斯牛顿法步

实际中，$X^TX$往往不是满秩矩阵，此时可引入正则化项

模型可推广至**广义线性模型**：$\large y=g^{-1}(w^Tx+b)$



**损失函数**

+ Least Absolute Deviations(LAS)： $L=\sum_i|y_i-\hat{y}_i|$ 

  对异常值更加稳定

+ Odinary Least Squares(OLS)： $L=\sum_i(y_i-\hat{y}_i)^2$
  数学基础更加扎实，与统计学最大似然估计法的结果一致

**模型评估**

+ 均方差(MSE）:    $\large MSE=\cfrac{1}{n}\sum_{i=1}^n(y_i-\hat{y}_i)^2=\cfrac{1}{n}L$，平均误差=$\sqrt{MSE}$
+ 决定系数（coefficient of determination）：$\large SS_{tot}=\sum_i(y_i-\bar{y})^2,\quad SS_{res}=\sum_i(y_i-\hat{y}_i)^2,\quad R^2=1-\cfrac{SS_{res}}{SS_{tot}} $，决定系数表示有多少的因变量变化能由模型解释

```python
from sklearn.linear_model import LinearRegression
import statsmodels.api as sm
from statsmodels.sandbox.regression.predstd import wls_prediction_std

def linearModel(data):
    """
    线性回归模型机器学习
    
    参数
    ----
    data : DataFrame，建模数据
    """
    features = ["x"]
    labels = ["y"]
    # 划分训练集和测试集
    trainData = data[:15]
    testData = data[15:]
    
    # 产生并训练模型
    # 创建一个线性回归模型
    model = linear_model.LinearRegression()
    # 训练模型，估计模型参数
    model.fit(trainData[features], trainData[labels])
    #  斜率：model.coef_，截距：model.intercept_
    
    # 评价模型效果
    # 均方差(The mean squared error)，均方差越小越好
    error = np.mean(
        (model.predict(testData[features]) - testData[labels]) ** 2)
    # 决定系数(Coefficient of determination)，决定系数越接近1越好
    score = model.score(testData[features], testData[labels])
    
def linearModel(data):
    """
    线性回归统计性质分析

    参数
    ----
    data : DataFrame，建模数据
    """
    features = ["x"]
    labels = ["y"]
    Y = data[labels]
    # 加入常量变量
    X = sm.add_constant(data[features])
    # 构建模型
    model = sm.OLS(Y, X)
    re = model.fit()
    
    # 分析模型效果
    # 整体统计分析结果
    print(re.summary())
    # 用f_test检测x对应的系数a是否显著，P-value小于0.05则拒绝
    print("检验假设x的系数等于0：")
    print(re.f_test("x=0"))
    
    # const并不显著，去掉这个常量变量
    model = sm.OLS(Y, data[features])
    resNew = model.fit()
    # 输出新模型的分析结果
    print(resNew.summary())
```



**惩罚项**

+ Lasso回归：使用L1范数  $L=\sum_i(y_i-ax_i-bx_i-c)^2+\alpha(|a|+|b|+|c|)$，**参数更容易为0变稀疏**

+ Ridge回归（岭回归）：使用L2范数  $L=\sum_i(y_i-ax_i-bx_i-c)^2+\alpha(a^2+b^2+c^2)$，**参数更容易减小降低复杂度**

**超参数** $\alpha>0$ 时，惩罚项会随 a,b,c 绝对值的增大而增大，即参数越远离0，惩罚就越大，因此在寻找L的最小值时，这一项会迫使参数估计值向0靠近

超参数存在时，采用网格搜寻（设置几组针对超参数的控制变量组，来找最小均方差的超参数）和验证集（将数据分为训练集，验证集，测试集）

```python
reg = linear_model.Ridge(alpha=.5)
reg.fit([[0, 0], [0, 0], [1, 1]], [0, .1, 1])
reg = linear_model.Lasso(alpha=0.1)
reg.fit([[0, 0], [1, 1]], [0, 1])
# statsmodels
model = sm.OLS(Y, X)
res = model.fit_regularized(alpha=alpha)
```

下图为$\alpha$改变时三个参数的变化规律

![image-20200604222642765](..\Resources\惩罚项.png)

+ 前向逐步回归：贪心，开始所有权重设为1，每一步对某个权重增加或减少一个值，迭代若干次即可收敛得到超参数

```python
def stageWise(xArr,yArr,eps=0.01,numIt=100):
    """
    前向逐步回归

    参数
    ----
    xArr : []，输入数据
    yArr : []，预测数据
    eps  : 步长
    numIt: 迭代次数
    """
    xMat = mat(xArr)
    yMat=mat(yArr).T
    yMean = mean(yMat,0)
    yMat = yMat - yMean     #can also regularize ys but will get smaller coef
    xMat = regularize(xMat)
    m,n=shape(xMat)
    #returnMat = zeros((numIt,n)) #testing code remove
    #ws = zeros((n,1)) #初始所有权重为0
    ws = ones((n,1)) #初始所有权重为1
    #wsMax = ws.copy()
    Mat = zeros((numIt, n))
    for i in range(numIt):
        if i%1000 ==0 : #每迭代1000次，打印归回系数
            print("第%d次迭代后回归系数为："%i,end ="")
            print(ws.T)
        lowestError = inf #初始误差设为正无穷大
        for j in range(n):
            for sign in [-1,1]: # 贪心算法，左右试探
                wsTest = ws.copy() # 初始化
                wsTest[j] += eps*sign #eps 为步长
                yTest = xMat*wsTest #预测值
                rssE = rssError(yMat.A,yTest.A)
                if rssE < lowestError:
                    lowestError = rssE
                    wsMax = wsTest
        ws = wsMax.copy()
        Mat[i,:]=ws.T
    return Mat
```

相比假设检验更加自动化，工程化，理论基础较差，可解释性差



**假设检验**

理论基础更牢，更容易理解数据之间关系，需要较多人工干预，随意性较大



**局部加权线性回归（Locally Weighted Linear Regression, LWLR）**

一种非参数算法，没有训练步骤，而是直接使用训练集进行预测。在做预测时，更多地参考距离预测样本近的已知样本，而更少地参考距离预测样本远的已知样本

原均方差和修改后均方差如下所示：

$\large \mathcal{L} = \dfrac{1}{2} \left[ \left(y^{(1)} -  \boldsymbol{\theta}^T \mathbf{x}^{(1)} \right)^2 + \left(y^{(2)} -  \boldsymbol{\theta}^T \mathbf{x}^{(2)} \right)^2 + \cdots +  \left(y^{(m)} - \boldsymbol{\theta}^T \mathbf{x}^{(m)} \right)^2 \right]$

$\large \begin{align*} \mathcal{L} &= \dfrac{1}{2} \left[ w^{(1)}  \left(y^{(1)} - \boldsymbol{\theta}^T \mathbf{x}^{(1)} \right)^2 +  w^{(2)} \left(y^{(2)} - \boldsymbol{\theta}^T \mathbf{x}^{(2)} \right)^2 + \cdots + w^{(m)} \left(y^{(m)} - \boldsymbol{\theta}^T  \mathbf{x}^{(m)} \right)^2 \right] \\ &= \frac{1}{2} \sum_{i=1}^m  w^{(i)} \left(y^{(i)} - \boldsymbol{\theta}^T \mathbf{x}^{(i)}\right)^2 \end{align*}$

修改后的加上了权重w：

$\large w^{(i)} = \exp \left( - \dfrac{\left(\mathbf{x}^{(i)} - \mathbf{x}\right)^2}{2k^2} \right)$

缺点是每个点做预测时都要使用整个数据集，计算量大，可改进



**分位数回归(Quantile Regression)**

普通的回归分析，只得到y的期望；分位数回归，可以探索y的完整分布状况

![image-20201112164901096](..\Resources\分位数回归.png)

分别取多个分位点[0,1]来进行回归拟合，得到若干条回归线（例：分位点0.9，得到的回归线下方有90%的数据点）

损失函数**Quantile Loss**(QL)：$L_q(y,\hat{y})=q(y-\hat{y})_+(1-q)(\hat{y}-y)_+$，当$q=0.5$时变为平均绝对值误差



## 对数几率回归(Logistic Regression)

无需事先假设数据分布，可以得到近似概率预测，有利于需要利用概率辅助决策的任务

考虑用广义线性模型：$y=g^{-1}(w^Tx+b)$解决分类问题，此时联系函数为单位阶跃函数，但其不连续，    用对数几率函数替代：$y=\cfrac{1}{1+e^{-(w^Tx+b)}}$，也即：$ln\cfrac{y}{1-y}=w^Tx+b$，将y视为后验概率估计，则可重写为$ln\cfrac{P(y=1|x)}{P(y=0|x)}=w^Tx+b$，其中$\cfrac{P}{1-P}$为**事件发生比**（odds）

模型认为观察得到的结果由正效用$P(y=1|x)$和负效用$P(y=0|x)$确定（称为隐含变量）

显然有**对数几率回归模型**：$P(y=1|x)=\cfrac{ e^{(w^Tx+b)}}{1+e^{(w^Tx+b)}}=\pi(x)，P(y=0|x)=\cfrac{1}{1+e^{(w^Tx+b)}}=1-\pi(x)$

似然函数为：$\large \prod_{i=1}^N[\pi(x_i)]^{y_i}[1-\pi(x_i)]^{1-y_i}$，定义广义参数：$\beta=(w_1,...,w_n;b)^T$

似然函数取对数作为**损失函数**： $\large L(w)=\sum_{i=1}^N[y_iln\pi(x_i)+(1-y_i)ln(1-\pi(x_i)]=\sum_{i=1}^N[y_i\beta^Tx_i-ln(1+e^{\beta^Tx_i})]$

可使用改进的迭代尺度法或牛顿法解决最大熵最优化问题

<img src="..\Resources\逻辑函数近似.png" alt="image-20200611103957090" style="zoom:80%;" />



```python
from sklearn.model_selection import train_test_split
import statsmodels.api as sm
from statsmodels.graphics.mosaicplot import mosaic

data = pd.read_csv(path)
cols = ["age", "education_num", "capital_gain", "capital_loss", "hours_per_week", "label"]
data = data[cols]
data[["age", "hours_per_week", "education_num", "label_code"]].hist(
     rwidth=0.9, grid=False, figsize=(8, 8), alpha=0.6, color="grey")
plt.show()

# 显示基本统计信息
print(data.describe(include="all"))
# 计算education_num, label交叉报表
cross1 = pd.crosstab(pd.qcut(data["education_num"],  [0, .25, .5, .75, 1]), data["label"])
print(cross1)
# 将交叉报表图形化
props = lambda key: {"color": "0.45"} if ' >50K' in key else {"color": "#C6E2FF"}
mosaic(cross1[[" >50K", " <=50K"]].stack(), properties=props)
# 计算hours_per_week, label交叉报表
cross2 = pd.crosstab(pd.cut(data["hours_per_week"], 5), data["label"])
# 将交叉报表归一化，利于分析数据
cross2_norm = cross2.div(cross2.sum(1).astype(float), axis=0)
print(cross2_norm)
# 图形化归一化后的交叉报表
cross2_norm.plot(kind="bar", color=["#C6E2FF", "0.45"], rot=0)
plt.show()

# 将数据分为训练集和测试集
trainSet, testSet = train_test_split(data, test_size=0.2, random_state=2310)
# 搭建逻辑回归模型，并训练模型
formula = "label_code ~ age + education_num + capital_gain + capital_loss + hours_per_week"
model = sm.Logit.from_formula(formula, data=data)
re = model.fit()

# 整体统计分析结果
print(re.summary())
# 计算各个变量对事件发生比的影响
# conf里面的三列，分别对应着估计值的下界、上界和估计值本身
conf = re.conf_int()
conf['OR'] = re.params
conf.columns = ['2.5%', '97.5%', 'OR']
print(np.exp(conf))
# 计算各个变量的边际效应
print(re.get_margeff(at="overall").summary())

# 计算事件发生的概率
testSet["prob"] = re.predict(testSet)
# 根据预测的概率，得出最终的预测
testSet["pred"] = testSet.apply(lambda x: 1 if x["prob"] > alpha else 0, axis=1)
```

**多元分类**

+ 多元逻辑回归：使用多个隐含变量模型
+ OvO：一对一，OvR：一对其余，MvM：多对多（纠错输出码，ECOC）

```python
from sklearn.linear_model import LogisticRegression

model = LogisticRegression(multi_class='multinomial', solver='sag',max_iter=1000)
# model = LogisticRegression(multi_class='ovr', solver='sag',max_iter=1000)
model.fit(data[features], data[labels])
```

**非均衡数据集**

数据标签偏向若干个，可通过修改损失函数里不同类别的权重来解决，使用再缩放：$\cfrac{y^*}{1-y^*}=\cfrac{y}{1-y}\times\cfrac{m^-}{m^+}$

```python
# 通过调整各个类别的比重，解决非均衡数据集的问题
positiveWeight = len(Y[Y>0]) / float(len(Y))
classWeight = {1: 1. / positiveWeight, 0: 1. / (1 - positiveWeight)}
# 为了消除惩罚项的干扰，将惩罚系数设为很大
model = LogisticRegression(class_weight=classWeight, C=1e4)
model.fit(X, Y.ravel())
```



## 支持向量机(Support Vector Machines,SVM)

如图，空间中的直线可以用一个线性方程来表示：$f(x)=w^\top x+b=0$ ，w为法向量，法向量指向一侧为正类

**函数间隔**：样本点 $\large \hat{\gamma_i}=y_i(w·x+b)，$超平面 $\large \hat{\gamma}=\min\hat{\gamma_i}$，表示分类的正确性

**几何间隔**：$\large \gamma = \cfrac{1}{||w||}\hat{\gamma}$，表示点与超平面距离（$f(X)=W^\top X+b=W^\top(X_p+r\cfrac{W}{||W||})+b=W^\top X_p+b+r\cfrac{W^\top W}{||W||}=r||W||$）

<img src="..\Resources\svm向量基础.png" alt="image-20200629225442920" style="zoom:80%;" />

**硬间隔最大化**

原始问题为：
$$
\large{
\max_{w,b}\cfrac{2}{||w||}\\
s.t.\quad y_i(w·x_i+b)\geqslant1
}
$$

等价替换：
$$
\large{
\min_{w,b}\frac12||w||^2\\
s.t.\quad y_i(w·x_i+b)-1\geqslant0
}
$$
此时演变成一个**凸二次规划问题**，分类决策函数为$f(x)=sign(w^*·x+b^*)$



**软间隔最大化**

对于**线性不可分问题**，需要加入**松弛参数$\xi$**和**惩罚参数$C$**，其中$\xi_i$与点 i 离相应虚线的距离成正比，表示数据 i 这一点违反自身分类原则的程度，所有点的$\xi_i$和越小越好，合并损失函数：
$$
\large{
\min_{w,b,\xi}\,\, \frac12||w||^2+C\sum_{i=1}^N\xi_i\\
s.t. \quad y_i(w·x_i+b)\geqslant1-\xi_i,\quad \xi_i\geqslant0
}
$$
将上述原始问题转化为对偶问题：
$$
\large{
\max_{\alpha}\,\, -\frac12 \sum_{i=1}^N\sum_{j=1}^N\alpha_i\alpha_jy_iy_j(x_i·x_j)+\sum_{i=1}^N\alpha_i\\
s.t.\quad \sum_{i=1}^N\alpha_iy_i=0, \quad 0\leqslant\alpha_i\leqslant C
}
$$
事实上是寻找与被测数据相似的训练数据，并将相应的因变量加权平均得到最后的预测值。只有在虚线上或虚线内的点权重才不为0，其他点权重都为0：

<img src="..\Resources\svm支持向量.png" alt="image-20200622181820083" style="zoom:50%;" />

引入合页损失函数（取正值）后，可将上述原始最优化问题等价为：
$$
\large{
\min_{w,b,\xi}\quad \lambda||w||^2+\sum_{i=1}^N[1-y_i(w·x_i+b)]_+
}
$$
损失函数的前一部分为**L2惩罚项**，后一部分为**预测损失LL（hinge loss）**，代替0/1损失函数

其中超参数 C 是模型预测损失的权重，C 越大表示模型越严格，margin越小，考虑的点越少，称为**hard margin**，C越小考虑的点越多，称为**soft margin**

<img src="..\Resources\svm超参数.png" alt="image-20200615221059133" style="zoom:60%;" />

**核函数**

$K(x_i,x_j)=\phi(x_i)·\phi(x_j)$ ，其中$\phi(x)$为空间变换

利用核函数，可以极大减少模型运算量，隐式地在特征空间进行学习，不需要显式定义特征空间和映射函数，并且完成未知的空间变换，将对偶问题中的向量点乘变为核函数即可：
$$
\large{
max_{\alpha}\,\, -\frac12 \sum_{i=1}^N\sum_{j=1}^N\alpha_i\alpha_jy_iy_jK(x_i,x_j)+\sum_{i=1}^N\alpha_i\\
s.t.\quad \sum_{i=1}^N\alpha_iy_i=0, \quad 0\leqslant\alpha_i\leqslant C\\
f(x)=sign(\sum_{i=1}^N\alpha_i^*y_iK(x_i,x)+b^*)
}
$$
这等价于经过映射函数将输入空间变换到一个新的特征空间中，上述表达式也是广义支持向量机的形式

当核函数对应的Gram矩阵是半正定矩阵时，核函数为正定核，可以使用

实际应用中，可以用网格搜寻的办法找到最合适的核函数

<img src="..\Resources\常用核函数.png" alt="image-20200622182951633" style="zoom:67%;" />

**序列最小最优化算法（SMO）**

一种启发式动态规划算法，用于高效求解上述凸二次规划问题。包括求解两个变量二次规划的解析方法和选择变量的启发式方法

子问题一次选择两个变量，根据$\sum_{i=1}^N\alpha_iy_i=0$，其中只有一个自由变量，如果所有变量都满足KKT条件，则可输出



**Scale variant**

不带惩罚项的线性回归和逻辑回归对特征的线性变换是稳定的，但SVM对线性变化不稳定，变量的权重改变不可被修复。可以用**归一化**来去掉干扰因素



**支持向量回归（SVR）**

使用SVM模型，容忍f(x)与y之间最多有$\epsilon$的偏差

![image-20200630193740226](..\Resources\svr.png)

```python 
from sklearn.svm import SVC
from sklearn.metrics.pairwise import linear_kernel, laplacian_kernel, polynomial_kernel, rbf_kernel

model = SVC(kernel=linear_kernel, coef0=1)
model.fit(data[["x1", "x2"]], data["y"])
```







## 决策树(Decision Tree)

使用树形决策流程，将数据进行分类

寻找最优决策树是一个**NP完全问题**，只能退而求其次使用贪心算法

1. 特征选择

   选取对训练数据具有分类能力的特征，使用信息增益或者信息增益比选择特征

   **信息增益准则对可取值数目较多的属性有所偏好**，因此可用信息增益比作为替代

2. 决策树生成

   以下两种决策树不限制分支数

   + **ID3(Iterative Dichotomister 3)**：根节点选择**信息增益**最大的特征，若子节点标签只有一类则作为叶子节点，否则使用子节点的数据子集作为新数据集，计算剩余特征信息增益，再选取最大的，依次递归。相当于用极大似然法，只有树的生成，容易过拟合
   + **C4.5**：同上，改为使用**信息增益比**，并且子节点信息增益比小于一定阈值，则选择最多的标签作为该节点的标签

3. 剪枝

   决策树模型属于非参模型，容易发生过拟合问题，解决方法为剪枝（剪不好会欠拟合）

   + 前剪枝：作用于决策树生成过程中，如设置阈值限制高度；或基于贪心法使用验证集比较准确率，从而禁止展开分支节点
   + 后剪枝：作用与决策树生成之后，将一些不太必要的子树剪掉，剪掉的节点的纯度下降不明显。应用较广泛的为**消除误差剪枝法（REP）**：通过最小化带有正则化项的决策树损失函数：$C_\alpha(T)=\sum_{t=1}^{|T|}N_tH_t(T)+\alpha|T|$，其中$|T|$为树T的叶结点个数，t是树的叶节点，该叶节点有$N_t$个样本；将数据分为训练集、剪枝集、测试集，将不符合剪枝集分类的子树剪掉，且符合从下往上按层下边的全部剪完再剪上边的，称为bottom-up restriction。



**分类与回归树（CART）**：

限定决策树为**二叉树**

+ 分类树

  用基尼指数$Gini(D)$最小化准则

+ **回归树**

  回归树用平方误差最小化准则

  将输入空间划分为M个单元 $R_1,...,R_M$，每个单元上有一个固定输出值$c_m$，则**回归树模型**为：$f(x)=\sum_{m=1}^Mc_mI(x\in R_m)$

  **平方误差**：$\sum_{x_i\in R_m}(y_i-f(x_i))^2$，**输出值估计**：$\hat{c_m}=\cfrac{1}{N_m}\sum_{x_i\in R_m}y_i，N_m为R_m上样本个数$

  使用**启发式方法**对输入空间划分：

  1. 遍历所有特征 j 和切分点 s，求解最小化切分损失的 j 和 s：$min_{j,s}[min_{c_1}\sum_{x_i\in R_1(j,s)}(y_i-c_1)^2+min_{c_2}\sum_{x_i\in R_1(j,s)}(y_i-c_2)^2]$
  2. 用选定的 (j,s) 对划分区域：$R_1(j,s)=\{x|x^{(j)}\leqslant s\}，R_2(j,s)=\{x|x^{(j)}> s\}，\hat{c_m}=\cfrac{1}{N_m}\sum_{x_i\in R_m}y_i$
  3. 重复1、2直至满足条件，生成回归树

+ **剪枝算法**

  **子树整体损失函数**：$C_\alpha(T)=C(T)+\alpha|T|，\alpha\geqslant 0，T为任意子树，C(T)是训练数据的预测误差（如基尼指数），|T|为子树叶结点个数$

  1. 对于原树 $T_0$ 中每一分支节点$t$，计算剪枝后整体损失函数减少的程度：$g(t)=\cfrac{C(t)-C(T_t)}{|T_t|-1}$

     $C(t)$：剪掉所有 t 的子节点，把 t 作为叶子节点，分类中按多数、回归中按均值，计算误差（Gini或平方误差）即为$C(t)$

     $C(T_t)$：直接计算子树 t 的误差

  2. 剪去 $g(t)$ 最小的 $T_t$，得到 $T_1$，同时将最小的 $g(t)$ 设为$\alpha_1$，$T_1$ 为区间 $[\alpha_1,\alpha_2)$ 的最优子树

  3. 对 $T_i$ 剪枝得到 $T_{i+1}$，不断重复直到只有一个分支节点

  4. 用交叉验证法（在独立验证集上计算误差）在序列 $T_0,T_1,...,T_n$ 中选取最优子树



```python
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import roc_curve, auc
from sklearn.preprocessing import OneHotEncoder
# 单独使用决策树
dtModel = DecisionTreeClassifier(max_depth=2)
dtModel.fit(trainData[features], trainData[label])
dtProb = dtModel.predict_proba(testData[features])[:, 1]
```

决策树优点在于能够考虑多个变量，而且变量的线性变换是稳定的，缺点是模型最后一步算法比较薄弱。为了得到更好的预测效果，可以使用**模型联结主义**，将决策树作为整体模型的一部分和其他模型嵌套使用



**连续值处理**

将连续值特征的所有取值排序，取各区间中位点作为尝试划分点，选择使信息增益最大的中位点作为最终划分点，其增益作为特征的信息增益

**离散属性使用后，后代不能再用，但是连续属性可以**



**缺失值处理**

先计算各特征没有缺失值的信息增益，再乘以一个权重（无缺失值样本所占比例），作为该属性信息增益。再将含缺失值的样本划入所有子节点中，并改变其权重



**多变量决策树**

每个节点对属性的线性组合进行测试（属性乘以权重的线性分类器），以实现斜划分，减少分类次数





## 集成学习(Ensemble Method)

为了是模型间的组合更加自动化，只使用一种模型最好，将机器学习中比较简单的模型（弱学习器）组合成一个预测效果好的复杂模型（强学习器），即为集成方法

| 方法     | 样本                         | 基学习器                 | 并行性 | 偏向               |
| -------- | ---------------------------- | ------------------------ | ------ | ------------------ |
| Boosting | 训练集不变，权重变           | 分类误差小的学习器权重大 | 串行   | 降低偏差，易过拟合 |
| Bagging  | 有放回，独立均匀采样，重采样 | 权重相等                 | 并行   | 降低方差           |



### Boosting方法（Boosting methods）

**个体学习器间存在强依赖关系**，必须**串行**生成的序列化方法，关注**降低偏差(bias)**，但时间开销大

先从初始训练集训练出一个基学习器，再根据基学习器的表现对训练样本分布进行调整，使得先前基学习器做错的训练样本在后续受到更多关注，然后基于调整后的样本分布训练下一个基学习器，最终将T个基学习器加权结合

+ **AdaBoost算法**

  每一轮中提高前一轮被弱分类器分类错误的样本的权值，降低被分类正确的**样本权值**；

  组合时，采取加权多数表决的方法，加大分类误差率小的弱分类的权值，减小分类误差率大的弱分类的权值

  **算法步骤**：对于二分类$y\in\{-1,+1\}$问题

  1. 均匀初始化训练数据权值分布：$D_1=(w_{11},...,w_{1i},...,w_{1N}),w_{1i}=\frac1N$

  2. 对于$m=1,2,...,M$：

     - 使用具有权值$D_m$的训练数据集学习，得到基分类器：$G_m(x)$

     - 计算$G_m(x)$在训练数据集上的分类误差率：$e_m=\sum_{i=1}^Nw_{mi}I(G_m(x_i)\not=y_i)$

     - 计算$G_m(x)$的系数：$\alpha_m=\cfrac12ln\cfrac{1-e_m}{e_m}$

     - 更新训练数据集的权值分布，使被误分类的样本权重值增大$\cfrac{1-e_m}{e_m}$倍（$Z_m$是规范化因子，使$D_{m+1}$成为一个概率分布）：$D_{m+1}=(w_{m+1,1},...,w_{m+1,i},...,w_{m+1,N}),\quad w_{m+1,i}=\cfrac{w_{mi}}{Z_m}exp(-\alpha_my_iG_m(x_i)),\quad Z_M=\sum_{i=1}^Nw_{mi}exp(-\alpha_my_iG_m(x_i))$

  3. 构建基本分类器的线性组合：$G(x)=sign(\sum_{m=1}^M\alpha_mG_m(x))$

  AdaBoost算法可看作**前向分步算法的特例**，损失函数是指数函数     

  整体训练误差上界为：$\prod_m Z_m$

  通常只在**二分类问题**中使用，多分类使用变体**AdaBoost-SAMME**，回归问题使用变体**AdaBoost.R2**

  

+ **提升树（Boosting Tree）**  

  基函数为决策树 $T(x;\Theta_m)$ 的加法模型：$f(x)=\sum_{m=1}^MT(x;\Theta_m),\quad \hat\Theta_m=argmin_{\Theta_m}\sum_{i=1}^N L(y_i,f_{m-1}(x_i)+T(x_i;\Theta_m))$

  - **分类**：指数损失函数，变为Adaboost算法的特例；

  - **回归**：平方误差损失函数：$L(y_i,f_{m-1}(x_i)+T(x_i;\Theta_m))=[y_i-f_{m-1}(x_i)-T(x_i;\Theta_m)]^2=[r-T(x_i;\Theta_m)]$，只需拟合残差 r 即可，初始化：$f_0(x)=0$

  

+ **梯度提升决策树（Gradient Boosting Decision Trees，GBDT，GBTs）**

  损失函数是平方损失和指数损失时，加法模型与前向分步算法每一步优化很简单，但**对于一般损失函数而言不容易**，因此使用梯度提升法，使用**损失函数负梯度作为残差的近似值**（$f_m(x)-f_{m-1}(x)=-\cfrac{\part L}{\part f(x)}=T(x;\Theta_m)$）

  1. 初始化：$f_0(x)=argmin_c \sum_{i=1}^N L(y_i,c)$

  2. 对 $m=1,2,...,M$

     - 对 $i=1,2,...,N$，计算：$r_{mi}=-[\cfrac{\part L(y_i,f(x_i))}{\part f(x_i)}]_{f(x)=f_{m-1}(x)}$
     - 拟合 $r_{mi}$ 得到一个回归树，叶结点区域 $R_{mj},j=1,2,...,J$
     - 对 $j=1,2,...,J$，计算：$c_{mj}=argmin_c \sum_{x_i\in R_{mj}}L(y_i,f_{m-1}(x_i)+c)$
     - 更新 $f(x)=f_{m-1}(x)+\sum_{j=1}^J c_{mj}I(x\in R_{{mj}})$，可加上学习率 $\gamma$

  3. 得到回归树：$\hat{f}(x)=f_M(x)=\sum_{m=1}^M\sum_{j=1}^J c_{mj}I(x\in R_{{mj}})$

     

  GBTs损失函数里没有惩罚项，容易过拟合，可使用XGBoost算法或者与其他模型联结来解决

  第2步中不使用回归树而使用其他子模型，即为**梯度提升法**，GBDT时梯度提升法的一种最为广泛的实现

  

+ **XGBoost**

  

  

  ```python
  import xgboost as xgb
  # data
  xgb_train = xgb.DMatrix(X_train,y_train)
  xgb_test = xgb.DMatrix(X_test,y_test)
  # fit
  params = {
      'objective':'multi:softmax',# 学习目标，二分类binary:logistic，平方误差回归reg:squarederror，多分类multi:softmax
      'booster':'gbtree',# 子模型，gbtree, gblinear or dart
      'learning_rate':0.1,# 学习率
      'max_depth':5,
      'num_class':3,# 标签类别数
  }
  watchlist = [(xgb_train,'train'),(xgb_test,'test')]
  model = xgb.train(params, xgb_train, num_boost_round=10, evals=watchlist)
  model.save_model('./model.xgb')
  # predict
  bst = xgb.Booster()
  bst.load_model('./model.xgb')
  pred = bst.predict(xgb_test)
  # 基于历史预测值继续训练
  pred_train = model.predict(xgb_train,output_margin=True)
  pred_test = model.predict(xgb_test,output_margin=True)
  xgb_train.set_base_margin(pred_train)
  xgb_test.set_base_margin(pred_test)
  # 导出模型文件
  bst.dump_model('./xgb_model_dump.txt')
  # k折交叉验证
  res = xgb.cv(params, xgb_train, 50, nfold=5, seed=0, 
  callbacks=[xgb.callback.print_evaluation(show_stdv=False), xgb.callback.early_stop(5)])
  
  # scikit-learn API
  model = xgb.XGBRegressor()
  clf = GridSearchCV(model,{
      'objective':'reg:squarederror',
      'max_depth':range(2,3),
      'n_estimators':[20,50,70],
      'learning_rate':[0.05, 0.1, 0.2],
  }, n_jobs=-1)
  clf.fit(train_df[feature_names], train_df[label_names], 
          early_stopping_rounds=10, eval_metric="auc", eval_set=[(train_df[feature_names], train_df[label_names])])
  ```

  

  

### Bagging方法（Bootstrap Aggregating）

**个体学习器间不存在强依赖关系**（以样本扰动来近似学习器独立，使用有放回的采样，即**重采样**，用得到的随机子集进行训练），可同时生成的**并行**化方法，关注**降低方差(variance)**

+ **随机森林（Random Forests）**

  在Bagging的基础上，每一步随机选择含k个特征的特征子集，再从中选取一个最优的用于划分，推荐$k=log_2d$，不仅含有**样本扰动**，还有**属性扰动**，通常效果比Bagging好

  各个树相互独立时，可以降低犯错概率

  对于分类问题，结果等于各个树中出现次数最多的类别；对于回归问题，结果等于各个树结果的平均值

  随机来源及scikit-learn函数如下：

  <img src="..\Resources\随机森林.png" alt="image-20200623110624949" style="zoom: 67%;" />

+ **随机森林高维映射（Random Forest Embedding）**

  可以将随机森林当作非监督式学习使用，随机抽取特征组合成合成数据，与原始数据一起进行决策树训练。当分类结果误差较小时，说明各变量间的相关关系比较强烈

  <img src="..\Resources\rfe.png" alt="image-20200623111544046" style="zoom:50%;" />

  使用随机森林将低维数据映射到高维后，可以与其他模型联结：

  <img src="..\Resources\rfe2.png" alt="image-20200623111941192" style="zoom:55%;" />

```python
from sklearn.ensemble import RandomTreesEmbedding
from sklearn.naive_bayes import BernoulliNB
from sklearn.pipeline import Pipeline

pipe = Pipeline([("embedding", RandomTreesEmbedding(random_state=1024)),
        ("model", BernoulliNB())])
pipe.fit(data[["x1", "x2"]], data["y"])
prob = pipe.predict_proba(np.c_[X1.ravel(), X2.ravel()])[:, 0]
# 将模型的预测结果可视化
# 生成100*100的预测点集
x1 = np.linspace(min(data["x1"]) - 0.2, max(data["x1"]) + 0.2, 100)
x2 = np.linspace(min(data["x2"]) - 0.2, max(data["x2"]) + 0.2, 100)
X1, X2 = np.meshgrid(x1, x2)
# 预测点的类别
prob = pipe.predict_proba(np.c_[X1.ravel(), X2.ravel()])[:, 0]
prob = prob.reshape(X1.shape)
# 画轮廓线
ax.contourf(X1, X2, prob, levels=[0.5, 1], colors=["gray"], alpha=0.4)
plt.show()
```



### **Staking**

一种学习式结合方法

先用初始训练集训练初级学习器，然后生成一个新的数据集，即初级学习器的输出被当作样例输入特征，而样本的标记仍被当为样例标记，用来训练组合模型（如Logistic回归）



### 多样性

个体学习器准确性越高，多样性越大，则集成越好

分类器$h_i$与$h_j$的预测结果列联表为：

![image-20200707125217670](..\Resources\分类器列联表.png)

给出常见多样性度量：

+ 相关系数：$\rho_{ij}=\cfrac{ad-bc}{\sqrt{(a+b)(a+c)(c+d)(b+d)}}$，取值[-1,1]，
+ Q-统计量：$Q_{ij}=\cfrac{ad-bc}{ad+bc}$，与$\rho_{ij}$符号相同
+ $\kappa$-统计量：$\kappa=\cfrac{p_1-p_2}{1-p_2}，p_1=\cfrac{a+d}{m}，p_2=\cfrac{(a+b)(a+c)+(c+d)(b+d)}{m^2}$，取值多为[0,1]，完全一致则$\kappa=1$







# 生成式模型(Generative Model)

学习联合概率分布$P(X,Y)$，然后求出条件分布概率$P(Y|X)$

学习收敛速度更快，更好的实现增量学习，存在隐变量时可用



## 贝叶斯决策论(Bayes Dicision Theory)

**贝叶斯决策论**：概率框架下，实施决策的基本方法

- **最小错误率贝叶斯决策**

  以平均错误率最小为规则，进行分类决策

  $P(X)=\sum_{i=1}^KP(X|y_i)P(y_i)$，错误率：$P(e|X)=\begin{cases}p(y_2|X),X分类到y_1\\p(y_1|X),X分类到y_2\end{cases}$，平均错误率：$P(e)=\int P(e|X)P(X)dX$

- **最小风险贝叶斯决策**

  以各种错误分类所造成的平均风险最小为规则，进行分类决策

  假设有K种类别$y_1,...,y_K$，$\lambda_{ij}$是将一个真实标签为$y_j$的样本误分类为$y_i$所产生的损失，条件风险（期望损失）为：$R(y_i|x)=\sum_{j=1}^K\lambda_{ij}P(y_j|x)$，贝叶斯判定准则就是要最小化总体风险，贝叶斯最优分类器为：$h^*(x)=\arg\min_y R(y|x)$

  当目标是最小化分类错误率时，$\lambda_{ij}=\begin{cases} 0,\quad i=j\\1,\quad otherwise \end{cases}$，$h^*(x)=\arg\max_y P(y|x)$，即选择使后验概率最大的类别

  最小错误率贝叶斯决策是最小风险贝叶斯决策的一种特例



**贝叶斯定理**：$P(y|X)=\cfrac{P(X|y)P(y)}{P(X)}$

- $P(y|X)：$后验概率，表示得知样本特征情况下，其属于各类标签的概率
- $P(y)$：类先验概率，表示样本空间中各类样本所占比例，由大数定律可通过频率估计
- $P(X|y)$：类条件概率（似然），表示得知样本标签情况下，其特征取给定值的概率
- $P(X)$：用于归一化的证据因子，与类标记无关

加上拉普拉斯平滑：$\hat{P}(c)=\cfrac{|D_c|+\lambda}{|D|+K\lambda},\quad \hat{P}(x_i|c)=\cfrac{|D_{c,x_i}|+\lambda}{|D_c|+K_i\lambda}$，解决训练集某特征不出现的情况



**朴素贝叶斯假设(Naive Bayes Assumption)**

假设各特征相互独立：$P(X_1=x_1,X_2=x_2,...,X_d=x_d|y=y_k)=\prod_{i=1}^N P(X_i=x_i|y=y_k),\quad P(X)=\prod_{i=1}^d P(X_i=x_i)$ ，越独立效果越好

**朴素贝叶斯法**

基于贝叶斯定理与朴素贝叶斯假设的分类方法。先利用独立条件根据样本求得先验概率和类条件概率，再使用极大似然估计或者贝叶斯估计，求得各个后验概率值，取最大概率作为估计值。朴素贝叶斯最优分类器为：$h_{nb}^*(x)=\arg\min_y P(y)\prod_{i=1}^d P(y_i|x)$

对于连续属性，假设似然满足正态分布：$p(x|c)\sim \Nu(\mu_c,\sigma_c^2)$，则参数的极大似然估计为：$\hat{\mu}_c=\cfrac{1}{|D_c|}\sum_{x\in D_c}x,\quad \hat{\sigma}_c^2=\cfrac{1}{|D_c|}\sum_{x\in D_c}(x-\hat{\mu})(x-\hat{\mu})^T$，类条件概率估计为：$\hat{p}(x_i|c)=\cfrac{1}{\sqrt{2\pi}\sigma_{c,i}}exp(-\cfrac{(x_i-\mu_{c,i})^2}{2\sigma_{c,i}^2})$，多变量：$p(x)=\cfrac{1}{(2\pi)^{n/2}|\Sigma|^{1/2}}\exp\{ -\cfrac{1}{2}(X-\mu)^\top\Sigma^{-1}(X-\mu) \}$

马氏距离：$\sqrt{(X-\mu)^\top\Sigma^{-1}(X-\mu)}$，表示数据的协方差距离，是一种计算两个未知样本集的相似度的方法



**概率密度函数估计方法**

- 参数估计：已知概率密度函数的形式，只是其中几个参数未知，目标是根据样本估计这些参数的值
  - **最大似然估计(Maximum Likelihood Estimation, MLE)**

    频率学派，认为估计参数为定值，通过最大化似然求得估计值：$P(D_c|\theta_c)=\prod_{x\in D_c}P(x|\theta_c)$，$Dc$为训练集 D 中第 c 类样本组成的集合，或使用对数似然 $LL(\theta_c)=log P(D_c|\theta_c)$避免下溢。

  - **贝叶斯估计(Bayesian Estimation)**

    贝叶斯学派，认为估计参数是未观察到的随机变量，也有概率分布。可假定一个先验分布 $p(\theta)$，计算条件分布 $p(X|\theta)=\prod_{i=1}^Np(x_i|\theta)$，再计算后验分布 $p(\theta|X)$，得贝叶斯估计量为：$\hat\theta=\int \theta\cdot p(\theta|X)d\theta$。当样本数足够大时，两种的参数估计值相同，当样本小且参数先验分布较准确时，贝叶斯估计较准确。

- 非参数估计：概率密度函数的形式未知，直接估计概率密度函数的方法



**半朴素贝叶斯分类器(semi-naive Bayes classifiers)**

适当考虑一部分属性间的相互依赖信息。**独依赖估计(One-Dependent Estimator,ODE)**即假设每个属性在类别之外最多仅依赖于一个其他属性。

- **Super-Parent ODE(SPODE)**：假设所有属性都依赖于同一个属性（超父），通过交叉验证等模型选择方法来确定超父属性
- **Tree Augmented naive Bayes(TAN)**：在最大带权生成树算法的基础上，简化属性间依赖关系
- **Averaged One-Dependent Estimator(AODE)**：尝试将每个属性作为超父来构建SPODE，再将具有足够训练数据支撑的SPODE集成起来



**贝叶斯网(Bayesian network)**

贝叶斯网表示：$B=<G,\Theta>$，$G$描述一个有向无环图，$\Theta$包含每个属性的条件 $\theta_{x_i|\pi_i}=P_B(x_i|\pi_i)$，$\pi_i$ 为 $x_i$ 的父节点集，不相连的属性独立：$P_B(x_1,x_2,...,x_d)=\prod_{i=1}^dP_B(x_i|\pi_i)$

![image-20201125150911739](..\Resources\贝叶斯网.png)

图中：$P(x_1,x_2,x_3,x_4,x_5)=P(x_1)P(x_2)P(x_3|x_1)P(x_4|x_1,x_2)P(x_5|x_2)$，给定$x_1$时$x_3,x_4$独立，给定$x_2$时$x_4,x_5$独立，分别记为：$x_3\bot x_4|x_1$，$x_4\bot x_5|x_2$

**贝叶斯网中三个变量间的典型依赖关系**

![image-20201125152210332](..\Resources\贝叶斯网三种依赖关系.png)

- 同父结构：给定父结点取值，子结点条件独立，$x_3\bot x_4|x_1$
- V型结构：给定子结点取值，父结点必不独立；若子结点取值完全未知，则父结点独立（边际独立性）
- 顺序结构：给定中间结点取值，两头结点独立，$y\bot z|x$

**有向分离(D-separation)**：找出有向图中变量间的条件独立性——1. 用无向边连接所有V型结构的父结点，2. 将所有有向边改为无向边

得到**道德图**。如果去除集合 $\vec{z}$，x和y分属两个连通分支，则 x 和 y 被 $\vec{z}$ 有向分离，$x\bot y|\vec{z}$

![image-20201125154144717](..\Resources\道德图.png)







NLP

包含：伯努利模型，多项式模型，高斯模型

> NLP特征提取字典法：将出现的文字组成一个字典X，出现的记为1，X为非常稀疏的向量

+ **伯努利模型**

  $p(c_i|\vec{w})=\cfrac{p(\vec{w}|c_i)p(c_i)}{p(\vec{w})},\quad c_i为类别i,\quad \vec{w}为特征向量$

  多元伯努利模型的变量 y 的分布概率等于各类别在训练数据中的占比，每个字的条件概率等于这个字在这个类别里出现的比例

  - 训练集没有出现过的字没办法预测，这时可加入**平滑项**，将$\cfrac{p(\vec{w}|c_i)}{p(\vec{w})}$的计算公式分母上加$2\alpha$，分子上加$\alpha$（平滑系数） 
  - 为避免连乘导致的下溢出或浮点数舍入错误，再加一层取对数

+ **多项式模型**

  更改特征提取方法，X的长度与文本字数相同，第i个元素表示第i个位置上出现的文字的字典序号

  变量y的分布概率$\hat{\theta_l}$等于各类别在训练数据中的占比，每个字的条件概率$\hat{p_{j,l}}$等于这个字的出现次数占这个类别的总字数的比例

+ **TD-IDF**

  文字对文本的影响主要有：

  - TF：某个文字在文本中出现的比例越高，与主题越相关

  - IDF：如果某个文字在几乎所有文本中都出现，说明它是常用字

  $TF_{i,k}=x_{i,k}/\sum_kx_{i,k}$，$IDF_k=ln(m/\sum_i1_{\{x_{i,k}>0\}})$，$TFIDF_{i,k}=TF_{i,k}IDF_{k}$

  常对文本向量进行TF-IDF 变换后在使用多项式模型

```python
from sklearn.feature_extraction.text import CountVectorizer, TfidfTransformer
from sklearn.metrics import classification_report
from sklearn.naive_bayes import BernoulliNB, MultinomialNB
from sklearn.preprocessing import LabelEncoder
from sklearn.pipeline import Pipeline

def trainBernoulliNB(data):
    """
    使用伯努利模型对数据建模
    """
    # 生成量化文本向量
    vect = CountVectorizer(token_pattern=r"(?u)\b\w+\b", binary=True)
    X = vect.fit_transform(data["content"])
    # 生成量化标签字典
    le = LabelEncoder()
    Y = le.fit_transform(data["label"])
    model = BernoulliNB()
    model.fit(X, Y)
    return vect, le, model

def trainMultinomialNB(data):
    """
    使用多项式模型对数据进行建模
    """
    pipe = Pipeline([("vect", CountVectorizer(token_pattern=r"(?u)\b\w+\b")),
        ("model", MultinomialNB())])
    le = LabelEncoder()
    Y = le.fit_transform(data["label"])
    pipe.fit(data["content"], Y)
    return le, pipe

def trainMultinomialNBWithTFIDF(data):
    """
    使用TFIDF+多项式模型对数据建模
    """
    pipe = Pipeline([("vect", CountVectorizer(token_pattern=r"(?u)\b\w+\b")),
        ("tfidf", TfidfTransformer(norm=None, sublinear_tf=True)),
        ("model", MultinomialNB())])
    le = LabelEncoder()
    Y = le.fit_transform(data["label"])
    pipe.fit(data["content"], Y)
    return le, pipe

def trainModel(trainData, testData, testDocs, docs):
    """
    对分词后的文本数据分别使用多项式和伯努利模型进行分类
    """
    # 伯努利模型
    vect, le, model = trainBernoulliNB(trainData)
    pred = le.classes_[model.predict(vect.transform(testDocs))]
    # 传入准确值和预测值，生成分析报告
    print(classification_report(
        le.transform(testData["label"]),
        model.predict(vect.transform(testData["content"])),
        target_names=le.classes_))
    # 多项式模型
    le, pipe = trainMultinomialNB(trainData)
    pred = le.classes_[pipe.predict(testDocs)]
    print(classification_report(
        le.transform(testData["label"]),
        pipe.predict(testData["content"]),
        target_names=le.classes_))
    # TFIDF+多项式模型
    le, pipe = trainMultinomialNBWithTFIDF(trainData)
    pred = le.classes_[pipe.predict(testDocs)]
    print(classification_report(
        le.transform(testData["label"]),
        pipe.predict(testData["content"]),
        target_names=le.classes_))
```



## 判别分析(Discriminant Analysis)

与朴素贝叶斯相比，允许变量间存在关系

### 线性判别函数

- 单线基准

  $d_i(X)=W_i^\top X$，共$M$个函数

  当$d_i(X)>0,d_{j\not=i}(X)<0$时，可判定样本属于第 i 类；当 $d_i(X)>0$多于一个时，为不确定区

- 多线基准

  $d_{ij}(X)=W_{ij}^\top X,\quad d_{ji}(X)=-d_{ij}(X)$，共$M(M-1)/2$个函数

  当$d_{ij}(X)>0,j\not=i$时，可判定样本属于第 i 类；当存在 $d_{ij}(X)<0$多于一个时，为不确定区；

  相比第一种，线性可分的可能性要更大一些

- 多线基准特例

  $d_{ij}(X)=d_i(X)-d_j(X),\quad d_i(X)=W_i^\top X$，共$M$个函数

  当$d_i(X)>d_j(X),j\not=i$时，可判定样本属于第 i 类

  除边界外没有不确定区



**广义线性判别函数**

$Y^*=[f_1(X^*),f_2(X^*),...,f_k(X^*),1]^\top$，$d(Y)=W^\top Y^*$

存在的问题：1. 非线性变换可能非常复杂 2. 维数大大增加： 维数灾难



### 线性判别分析（Fisher Linear Discriminant Analysis，LDA）

在二维平面上，要求把点投影到一条直线上，直线的**方向向量为$w$**，则点X的投影点为$w^TX$，假设只有两个类别0、1，降维后，希望同类别投影点近（协方差小），不同类别投影点远（中心距离大），即：
$$
\large{
记第i类:集合X_i\quad均值向量\mu_i=\cfrac{1}{||D_i||}\sum_jx_j\quad协方差矩阵\Sigma_i=\sum_j(x_j-\mu_i)(x_j-\mu_i)^\top\quad\\
各投影点的均值\tilde{\mu}_i=w^\top\mu_i\quad投影点类内协方差\tilde{\Sigma}_i=w^\top\Sigma_iw\\
最大化目标：J=\cfrac{(\tilde{\mu_0}-\tilde{\mu_1})^2}{\tilde{\Sigma}_0+\tilde{\Sigma}_1}=\cfrac{||w^\top\mu_0-w^\top\mu_1||_2^2}{w^\top\Sigma_0w+w^\top\Sigma_1w}=\cfrac{w^\top(\mu_0-\mu_1)(\mu_0-\mu_1)^\top w}{w^\top(\Sigma_0+\Sigma_1)w}=\cfrac{\tilde{S}_b}{\tilde{S}_w}\\
定义\quad类间散度矩阵：S_b=(\mu_0-\mu_1)(\mu_0-\mu_1)^\top\quad 类内散度矩阵：S_w=\Sigma_0+\Sigma_1\\
则：J=\cfrac{w^\top S_bw}{w^\top S_ww}\\
解得：w^*=S_w^{-1}(\mu_0-\mu_1)\\
分割阈值：y_0=\cfrac{||D_0||\tilde{\mu}_0+||D_1||\tilde{\mu}_1}{||D_0||+||D_1||}
}
$$
只能处理连续型变量，$X|y=0\sim N(\mu_0,\Sigma)$，$X|y=1\sim N(\mu_1,\Sigma)$，$P(y=0)=\theta_0$，$P(y=1)=\theta_1$

模型要求：

1. 变量服从正态分布，因此要连续；
2. 对于不同类别，自变量协方差一样，只是期望不一样，只关心各类别中心位置；
3. 协方差$\Sigma$是对角矩阵时，变量相互独立

参数估计：

1. $\theta_l$：等于各类别在训练数据中的占比
2. $\mu_l$：等于训练数据里各类别的平均值
3. $\Sigma$：等于各类别内部协方差的加权平均，权重为类别内数据的个数

LDA的预测公式与逻辑回归的一样，在满足模型要求时，往往生成式模型效果更好

LDA可以用作降维，$\mu_l$与降维理论中$\mu_l$一样，$\Sigma$与降维理论中$\cfrac{1}{m}s_W$一样

```python
from sklearn import datasets
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
# 生成数字集
digits = datasets.load_digits()
X = digits.data
y = digits.target
#输入降维后的维度进行降维
model = LinearDiscriminantAnalysis(n_components=3)
model.fit(X, y)
newX = model.transform(X)
```

**优点：**

- 相比较 PCA，LDA 更加擅长处理带有类别信息的数据；
- 线性模型对噪声的鲁棒性比较好，LDA 是一种有效的降维方法。

**缺点：**

- LDA对**数据的分布做出了很强的假设**，比如每个类别数据都是高斯分布、各个类的协方差相等。这些假设在实际中不一定完全满足。
- LDA**模型简单，表达能力有一定局限性**，但这可以通过引入**核函数**拓展 LDA 来处理分布比较复杂的数据。



### 二次判别分析（Quadratic Discriminant Analysis，QDA）

不要求自变量分布的协方差矩阵一样，但无降维功能，当协方差矩阵为对角矩阵时，二次判别变成高斯模型

调用GaussianNB或QuadraticDiscriminantAnalysis建模



## 隐马尔科夫模型(Hidden Markov Model,HMM)

当数据之间不再独立，数据间的顺序会对数据本身造成影响，此时称为序列数据，需要用隐马尔科夫模型来解决

可用于**标注问题**，描述由隐藏的马尔科夫链随机生成不可观测序列，再由各个状态生成一个观测序列，从而生成观测序列的过程

基于假设：齐次马尔科夫性，观测独立性
$$
状态集合：Q=\{q_1,q_2,...,q_N\}\quad观测集合：V=\{v_1,v_2,...,v_N\}\quad状态序列：I=\{i_1,i_2,...,i_T\}\quad观测序列：O=\{o_1,o_2,...,o_T\}\\
隐马尔科夫模型三要素—状态转移概率矩阵：A(a_{ij}=P(i_{t+1}=q_j|i_t=q_i))\quad观测概率矩阵：B(b_{j}(k)=P(o_t=v_k|i_t=q_j))\quad初始状态概率向量：\pi=(\pi_i)\\
$$
**三个基本问题**

+ **概率计算问题**

  已知模型$\lambda=(A,B,\pi)$和观测序列$O$，计算$P(O|\lambda)$

  - **前向算法**

    前向概率：$\alpha_t(i)=P(o_1,o_2,...,o_t,i_t=q_i|\lambda)$

    初值：$\alpha_1(i)=\pi_ib_i(o_1),\quad i=1,2,...,N$

    递推：$\alpha_{t+1}(i)=[\sum_{j=1}^N\alpha_t(j)a_{ji}]b_i(o_{t+1}),\quad i=1,2,...,N$

    终止：$P(O|\lambda)=\sum_{i=1}^N\alpha_T(i)$

    复杂度为：$O(N^2T)$

+ **学习问题**

  已知$O$，估计$\lambda$

  - 监督式

    使用频数 $A_{ij},B_{jk}$ 来估计 $a_{ij},b_j(k)$

  - 非监督式（Baum-Welch算法）

    使用EM算法

+ **预测问题**

  已知$O,\lambda$，估计$I$

  - 维特比算法

    使用动态规划，从$t=1$开始，递推计算时刻t 状态为 i 的各条路径最大概率，到时刻$t=T$选取最大概率                                                            





**应用**

+ 监督式学习（中文分词）

  multinomial HMM，包含Viterbi算法求解模型预测结果

  将文字分为若干种状态，再去根据y估计模型参数

+ 非监督式学习（股票市场）

  要用到最大期望算法（EM）来估计模型参数和预测量：先随机生成模型参数，通过E step求得预测值y，再通过M step求得估算的模型参数，重复交叉使用即可得到所有参数

  假设股票的日收益率和成交量服从正态分布，此时隐马尔科夫模型称为Gaussian HMM

  ```python
  from matplotlib.finance import candlestick_ochl
  from hmmlearn.hmm import GaussianHMM
  
  cols = ["r_5", "r_20", "a_5", "a_20"]
  # 参数为内在状态个数，先验分布的协方差矩阵类型，迭代次数
  model = GaussianHMM(n_components=3, covariance_type="full", n_iter=1000,
                      random_state=2010)
  model.fit(data[cols])
  hiddenStatus = model.predict(data[cols])
  ```

  





