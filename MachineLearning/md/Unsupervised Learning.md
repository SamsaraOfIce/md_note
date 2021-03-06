$K$为标签数，$d$为特征数，$K_i$为$X_i$的类别数，$N,n$为样本数，$D$为数据集，$D_c$为数据子集

# 聚类

样本集合用矩阵$X=[x_{ij}]$表示，$x_{ij}$代表第 j 个样本的第 i 个特征

**聚类距离**

- 闵可夫斯基距离

  $\large d_{ij}=(\sum_{k=1}^d|x_{ki}-x_{kj}|^p)^{\frac1p},p\geqslant 1$，$p=$1为曼哈顿距离，$p=2$为欧氏距离，$p=\infin$为切比雪夫距离（取各个坐标数值差的绝对值的最大值）

- 马哈拉诺比斯距离

  考虑各特征的相关性并与各特征尺度无关，$\large d_{ij}=[(x_i-x_j)^TS^{-1}(x_i-x_j)]^{\frac12}$，$S$ 为 $X$ 的协方差矩阵，$\large x_i=(x_{1i},x_{2i},...,x_{di})^\top$

- 相关系数

  $\large r_{ij}=\cfrac{\sum_{k=1}^m (x_{ki}-\bar{x}_i)(x_{kj}-\bar{x}_j)} {[\sum_{k=1}^m (x_{ki}-\bar{x}_i)^2\sum_{k=1}^m (x_{kj}-\bar{x}_j)^2]^\frac{1}{2}}$

- 夹角余弦

  $\large s_{ij}=\cfrac{\sum_{k=1}^m x_{ki}x_{kj}} {[\sum_{k=1}^m x_{ki}^2\sum_{k=1}^m x_{kj}^2]^\frac{1}{2}}$

**类（簇）**

$n_G$表示类G中样本个数，$d_{ij}$表示样本$x_i$与样本$x_j$之间的距离

判定属同类：T为给定正数，若集合G中任意两个样本$x_i,x_j$的距离$d_{ij}\leqslant T$，则G为一个类

类的特征： 

1. 均值（中心）：$\bar{x}_G=\cfrac{1}{n_G}\sum_{i=1}^{n_G} x_i$

2. 直径：$D_G=\max\,d_{ij}$

3. 样本散布矩阵：$A_G=\sum_{i=1}^{n_G}(x_i-\bar{x}_G)(x_i-\bar{x}_G)^\top$ 

   样本协方差矩阵：$S_G=\cfrac{1}{m-1}A_G$















## 层次聚类

## k均值(k-Means)



# 马尔科夫链(Markov Chain)

刻画随时间在状态之间转移的模型

一个随机变量序列$X=\{X_0,X_1,...,X_t,...\}$，$X_t$表示 $t$ 时刻的随机变量，其取值集合都为状态空间 $S$，随机变量可离散可连续（一般考虑离散）

+ **转移概率分布**

  具有马尔科夫性的随机序列称为马尔科夫链，其转移概率分布满足：$P(X_t|X_{t-1})=P(X_t|X_0,X_1,...,X_{t-1})$，若$P(X_t|X_{t-1})$与 $t$ 无关，则称为**时间齐次**的马尔科夫链

+ **转移概率矩阵**（随机矩阵，stochastic matrix）

  设转移概率：$p_{ij}=P(X_t=j|X_{t-1}=i),\,p_{ij}\geqslant0,\,\sum_jp_{ij}=1$，有转移概率矩阵：$P=[p_{ij}]$

  $\large p^{(n)}_{ij}(k)$：k 时刻，从状态 i 到状态 j ，经过 n 步的转移概率

  $\large f^{(n)}_{ij}$：经过 n 步，**首次**从 i 到达 j 的概率

  $\large f_{ij}=\sum_{n=1}^\infty f^{(n)}_{ij}$：**迟早**从 i 到达 j 的概率

  $\large \mu_{ij}=\sum_{n=1}^\infty nf^{(n)}_{ij}$：平均转移步数

  $\large \mu_i=\mu_{ii}$：从状态 i 首次返回状态 i 的平均步数

  $\large{ p^{(n)}_{ij}=\sum_{r=1}^n f^{(r)}_{ij}\cdot p^{(n-r)}_{jj}}$

  $\large p^{(m+n)}_{ij}(t)=\sum_{k\in S} p^{(m)}_{ik}(t)\cdot p^{(n)}_{kj}(t)$：Chapman–Kolmogorov 方程，用 m 步和 n 步转移概率来表示 m+n 步转移概率

+ **状态分布**

  设$\pi_i(t)$表示 $t$ 时刻状态为 $i$ 的概率 $P(X_t=i)$ ，则马尔科夫链在 $t$ 时刻的状态分布为：$\pi(t)=[\pi_1(t),\pi_2(t),...]^T$（通常初始分布$\pi(0)$只有一个分量是1，其余为0）

+ **状态分布转移方程**

  马尔科夫链的状态分布转移方程：$\pi(t)=P\pi(t-1)=P^t\pi(0)$

+ **平稳分布**

  若存在一个状态分布 $\pi=P\pi$，则 $\pi$ 为马尔科夫链的一个平稳分布

  求平稳分布可解方程组：$(P-E)X=0, \,\sum_ix_i=1, \,x_i\geqslant0$

+ **到达**

  $f_{ij}>0 \Leftrightarrow i\rightarrow j$

+ **相通**

  $f_{ij}>0,f_{ji}>0 \Leftrightarrow i\leftrightarrow j$

  如果两个状态相通，则称两个状态处于一个类中

+ **闭集**

  设C为状态空间S的一个子集，若从C中的任何一个状态不能达到C以外的任何状态，则称C为闭集

  单个状态构成的闭集称为**吸收态（即平稳分布）**



**马尔科夫链性质：**

1. **不可约(irreducible)**

   $\forall i,j\in S,\exist\,t,P(X_t=i|X_0=j)>0$

   即如果除了整个状态空间外，没有别的闭集的马尔科夫链称为不可约的

   不可约表示所有状态相通；可约表示可以转移到一个闭集中

   > **含有平稳分布的马尔科夫链可约**

2. **非周期(aperiodic)**

   $\forall i\in S,\,gcd(\,\{n|p^{(n)}_{ii}>0\}\,)=1$

   即所有状态都是非周期的

   > **不可约且非周期的有限状态马尔科夫链，有唯一平稳分布存在**

3. **正常返(positive recurrent)**

   $\forall i,j\in S,\, \lim_{n\to\infty}f^{(n)}_{ij}>0$

4. **遍历定理**

   **不可约，非周期且正常返的马尔科夫链，有唯一平稳分布，并且转移概率的极限分布是马尔可夫链的平稳分布**，即：$\large \lim_{t\to\infty}p(X_t=j|X_0=i)=\pi_j$，表示时间趋于无穷时达到任意一个状态的概率不为0的马尔科夫链的极限分布存在且收敛于平稳分布

   若$f(X)$是定义在状态空间上的函数，且 $E_\pi[\,|f(X)|\,]=\sum_i |f(i)|\pi_i<\infty$，则此时随机变量的函数的样本均值（时间均值）以概率1收敛于该函数的数学期望（空间均值）：$\large P\{\cfrac{1}{t}\sum_{s=1}^t f(x_s) \to E_\pi[\,|f(X)|\,]\}=1$

   一般取一个足够大的整数m，经过m次迭代后认为状态分布已经收敛于平稳分布，这时可得到**遍历均值**：$\hat{E}f=\cfrac{1}{n-m}\sum_{i=m+1}^nf(x_i)$

5. **可逆马尔可夫链(reversible)**

   $\forall i,j\in S,t$，满足**细致平衡方程(detailed balance equation)**：$p_{ij}\pi_i=p_{ji}\pi_j$，其中的状态分布$\pi_i$就是该马尔可夫链的平稳分布

   说明可逆马尔可夫链满足遍历定理条件，一定有唯一平稳分布

   可逆马尔可夫链以平稳分布作为初始分布，无论是面向未来还是过去，任何时刻状态都是平稳分布



**状态分类：**
$$
\large
状态
\begin{cases}
非常返(滑过态)\,f_{ii}<1\\常返(返回态)\,f_{ii}=1
\begin{cases}
零常返\,\mu_i=+\infin\\正常返\,\mu_i<+\infin
\begin{cases}
周期\,d_i>1\\非周期(遍历态)\,d_i=1
\end{cases}
\end{cases}
\end{cases}
$$

1. 单个状态构成的闭集称为**吸收态**($\large \Leftarrow p_{ii}=1,p_{ij,j\not=i}=0$)

2. 对于状态 $i\in S$，如果 $\large f_{ii}=1\Leftrightarrow\sum_{n=1}^\infty p^{(n)}_{ii}=\infty$，则称状态 i 为**常返态（返回态）**；如果 $\large f_{ii}<1 \Leftrightarrow\sum_{n=1}^\infty p^{(n)}_{ii}=\cfrac{1}{1-f_{ii}}<\infty$，则称状态 i 为**非常返态（滑过态）**

   常返态表示事件一定发生；滑过态表示事件有几率不发生（从其他状态转移不到此状态）

   常返态也可约束在闭集内	

3. 对于常返态 $i\in S$，如果 $\mu_i<+\infty$，则称状态 i 是**正常返**的；如果 $\mu_i=+\infty$，则称状态 i 是**零常返**的

   正常返表示有限步返回；零常返表示需要经过无限步才能返回

   > **有限状态马尔科夫链不存在零常返**

4. 对于正常返的 $i\in S$，如果 $gcd(\,\{n|p^{(n)}_{ii}>0\}\,)>1$，则称状态 i 是**周期**的；如果 $gcd(\,\{n|p^{(n)}_{ii}>0\}\,)=1$，则称状态 i 是**非周期（遍历态）**的

   类到类之间也有周期，如：(1,2)->(3,4)->(1,2)->(3,4)

   









































