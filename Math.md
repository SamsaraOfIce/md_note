

# 数学

$K$为标签数，$d$为特征数，$K_i$为$X_i$的类别数，$N$为样本数，$D$为数据集，$D_c$为数据子集

+ **核方法**

  优化问题中，当正则化项$\Omega(||h||_H)$单调递增，损失函数非负时，优化问题的最优解总可以表示成核函数的线性组合：$h^*(x)=\sum_{i=1}^m\alpha_iK(x,x_i)$

+ **信息论**

  默认log底数为2

  - **信息量**：$I(x_0)=-logP(x_0)$，表示获取信息的多少，事件发生概率越大，获取到的信息量越少，P为频率（0log0=0）
  - **熵(Entropy)**：$H(X)=-\sum_iP(x_i)logP(x_i)$，是信息量的期望，熵越大随机变量不确定性越大，当随机变量各取值概率一样时熵达到最大，单位比特
  - **条件熵**：$H(Y|X)=\sum_{i=1}^np_iH(Y|X=x_i)，X有n种取值$ ，表示在已知随机变量X的条件下随机变量Y的不确定性
  - **信息增益(InfoGain)**：$g(D,A)=H(D)-H(D|A)$，表示得知特征A的信息而使数据集D的分类的不确定性减少的程度，信息增益大的特征具有更强的分类能力
  - **信息增益比**：$g_R(D,A)=\cfrac{g(D,A)}{H_A(D)}$
  - **相对熵（KL散度）**：$D_{KL}(P||Q)=\sum_iP(x_i)ln\cfrac{P(x_i)}{Q(x_i)}=-H(P(x))+H(P,Q)$，表示如果用P来描述目标问题，而不是用Q来描述目标问题，得到的信息增量。在机器学习中，P往往用来表示样本的真实分布，Q用来表示模型所预测的分布，相对熵的值越小，表示P分布和Q分布越接近。可使用$D_{KL}(y||\hat{y})$评估label和predicts之间的差距
  - **交叉熵**：$H(P,Q)=-\sum_iP(x_i)lnQ(x_i)$ ，KL散度中前一部分P的熵不变，可使用交叉熵代替均方误差等作为loss函数，表示两个概率分布之间的距离
  - **基尼指数**：$Gini(p)=\sum_{k=1}^Kp_k(1-p_k)=1-\sum_{k=1}^Kp_k^2，K为类别数;二分类Gini(p)=2p_1p_2$；数据集被条件（$特征Ai==a$）划分为两个子集，则  $Gini(D,Ai)=p_{D_1}Gini(D_1)+p_{D_2}Gini(D_2)$  （**2分类只有1种分类方法，n分类有n种分类方法**）

+ **EM算法**

  用于含有隐变量的概率模型参数的极大似然估计

  不同的初值可能得到不同的参数估计值；不能保证找到全局最优值

  可用于生成模型的无监督学习
  $$
  记\quad 观测随机变量（不完全数据）Y\quad 隐随机变量Z\quad完全数据Y+Z\quad模型参数\theta（初值\theta^{(0)}）\\
  迭代求\quad L(\theta)=logP(Y|\theta) \quad的最大似然估计\quad\\
  E步：第i+1次迭代计算Q函数\quad Q(\theta,\theta^{(i)})=E_z[logP(Y,Z|\theta)|Y,\theta^{(i)}]=\sum_Z logP(Y,Z|\theta)P(Z|Y,\theta^{(i)})\\
  M步：\theta^{(i+1)}=arg\,max_\theta Q(\theta,\theta^{(i)})
  $$
  推广有GEM算法

+ **高斯混合模型**

  用任意概率分布代替高斯分布密度可得到一般混合模型

  高斯混合模型可以用EM算法估 计参数 $\theta=(\alpha_k,\theta_k)$
  $$
  具有分布概率:P(y|\theta)=\sum_{k=1}^K\alpha_k\phi(y|\theta_k)\\
  \alpha_k\geqslant0,\sum_{k=1}^K\alpha_k=1;\quad \phi(y|\theta_k)是高斯分布密度，\theta_k=（\mu_k,\sigma_k^2）
  $$
  


- **前向分步算法**

  为得到加法模型：$f(x)=\sum_{m=1}^M\beta_mb(x;\gamma_m)$，需要求解损失函数极小化问题：$min_{\beta_m,\gamma_m}\sum_{i=1}^NL(y_i,\sum_{m=1}^M\beta_mb(x;\gamma_m))$，前向分步算法将同时求解$m=1 toM$所有参数问题简化为逐次求解各个$\beta_m,\gamma_m$

  1. 初始化$f_0(x)=0$
  2. 对于$m=1,2,...,M$，$(\beta_m,\gamma_m)=argmin_{\beta,\gamma}\sum_{i=1}^NL(y_i,f_{m-1}(x_i)+\beta b(x;\gamma)),\quad f_m(x)=f_{m-1}(x)+\beta_m b(x;\gamma_m))$
  3. 得到加法模型：$f(x)=f_M(x)=\sum_{m=1}^M\beta_mb(x;\gamma_m)$




# 基础数学理论

## 可微性

一阶导数，**梯度**：$\nabla f(x)=(\cfrac{\part f(x)}{\part x_1},\cfrac{\part f(x)}{\part x_2},...,\cfrac{\part f(x)}{\part x_n})^\top$，记为$g(x)$

二阶导数，**Hesse矩阵**：$\nabla^2 f(x)$，为对称阵，记为$G(x)$

向量值函数$F=(F_1,F_2,...,F_m)^\top$的 **Jacobi 矩阵**：$J_F(x)=F'(x)=(\nabla F_1(x),\nabla F_2(x),...,\nabla F_m(x))^\top$

## 范数

向量$x$的范数满足：
$$
\large{
正定性：||x||\geqslant 0,||x||=0\Leftrightarrow x=0\\
齐次性：||\lambda x||=|\lambda|\,||x||,\lambda\in \R\\
三角不等式：||x+y||\leqslant ||x||+||y||
}
$$
矩阵$A\in \R^{n\times n}$的范数还需满足：
$$
\large{
乘法：||AB||\leqslant ||A||B||\\
向量范数与矩阵范数相容：||Ax||\leqslant||A||_\mu ||x||\\
向量范数的算子（矩阵）范数：||A||_\mu=max_{x\not=0} \cfrac{||Ax||}{||x||}=max_{||x||=1}||Ax||
}
$$


常用范数：

- p-范数：$\large ||x||_p=(\sum_{i=1}^n |x_i|^p)^{\frac{1}{p}}$
- 1-范数：$\large ||x||_1=\sum_{i=1}^n |x_i|$，对应算子范数—行和范数：$\large ||A||_{\infty}=max_{1\leqslant i\leqslant n}\sum_{j=1}^n |a_{ij}|$
- 2-范数：$\large ||x||_2=(\sum_{i=1}^n |x_i|^2)^{\frac{1}{2}}$，对应算子范数—列和范数：$\large ||A||_1=max_{1\leqslant j\leqslant n}\sum_{i=1}^n |a_{ij}|$
- $\infty$-范数：$\large ||x||_{\infty}=max_{1\leqslant i\leqslant n}|x_i|$，对应算子范数—谱范数：$\large ||A||_2=max\{\lambda|\lambda\in\lambda(A^TA)\}$

- F-范数：$\large ||A||_F=(\sum_{i=1}^n\sum_{j=1}^n a_{ij}^2)^{1/2}=\sqrt{tr(A^TA)}$



## 凸集与凸函数

**凸集**

$\large \forall x,y\in D,\forall \lambda\in[0,1],\lambda x+(1-\lambda)y\in D$，即集合中任意两点的线段仍属于该集合

**性质**

- $\alpha D=\{y|y=\alpha x,x\in D\}$是凸集
- 交集$D_1 \cap D_2$是凸集
- 和集$D_1+D_2=\{z|z=x+y,x\in D_1,y\in D_2\}$是凸集



**凸函数**

设函数$f:D\subset \R^n \rightarrow\R$，其中 $D$ 为凸集

- 凸函数：$\forall x,y\in D,\forall \lambda\in[0,1],f(\lambda x+(1-\lambda)y)\leqslant \lambda f(x)+(1-\lambda)f(y)$，充要条件：$\nabla^2 f(x)$ 对一切 $x\in D$ 为半正定
- 严格凸函数：$\forall x,y\in D,x\not=y,\forall \lambda\in[0,1],f(\lambda x+(1-\lambda)y)< \lambda f(x)+(1-\lambda)f(y)$，充分条件：$\nabla^2 f(x)$ 对一切 $x\in D$ 为正定
- 一致凸函数：$\exist\gamma>0, \forall x,y\in D,\forall \lambda\in[0,1],f(\lambda x+(1-\lambda)y)+\cfrac{1}{2}\lambda(1-\lambda)\gamma ||x-y||^2\leqslant \lambda f(x)+(1-\lambda)f(y)$，充要条件：$\nabla^2 f(x)$ 对一切 $x\in D$ 为一致正定

（以上后面的条件前提都为二阶连续可微）



## 概率论

**矩母函数**

随机变量X的矩母函数为：$\phi(t)=E[e^{tx}]$

有性质：$\phi^{(n)}(0)=E[X^n],n\geqslant1$；X+Y的矩母函数为相乘：$\phi_{X+Y}(t)=\phi_X(t)\phi_Y(t)$；矩母函数唯一的确定了分布函数



## 矩阵论

正定矩阵：给定一个大小为$n\times n$的实对称矩阵A，若对于任意长度为 n 的非零向量 $x$，有 $x^\top Ax>0$ 恒成立，则矩阵 A 为正定矩阵

半正定矩阵：给定一个大小为$n\times n$的实对称矩阵A，若对于任意长度为 n 的非零向量 $x$，有 $x^\top Ax\geqslant0$ 恒成立，则矩阵 A 为半正定矩阵

一致正定矩阵：给定一个大小为$n\times n$的实对称矩阵A，若存在常数$c>0$，使得对于任意长度为 n 的非零向量 $x$，有 $x^\top Ax\geqslant c||h||^2$ 恒成立，则矩阵 A 为一致正定矩阵



# 应用随机过程



## 计数过程

$\{N(t),t\geqslant0\}$，$N(t)$表示到时刻 t 为止发生的事件的总数

需满足：

1. $N(t)\geqslant0$
2. $N(t)$取整数值
3. 若$s<t$，则$N(s)\leqslant N(t)$
4. 对于$s<t$，$N(t)-N(s)$表示在区间 (s,t] 中发生的事件个数

**独立增量：**发生在不相交的时间区间中的事件个数彼此独立

> **独立增量过程一定是马尔科夫过程**

**平稳增量（时间齐次）：**在任意时间区间中发生的事件个数只依赖于时间区间的长度



## 泊松过程

| 名称     | 密度函数                             | 矩母函数$\phi(t)$            | 均值                 | 方差                   |
| -------- | ------------------------------------ | ---------------------------- | -------------------- | ---------------------- |
| 泊松分布 | $\cfrac{e^{-\lambda}\lambda^x}{x!}$  | $exp\{\lambda(e^t-1)\}$      | $\lambda$            | $\lambda$              |
| 指数分布 | $\lambda e^{-\lambda x},x\geqslant0$ | $\cfrac{\lambda}{\lambda-t}$ | $\cfrac{1}{\lambda}$ | $\cfrac{1}{\lambda^2}$ |

计数过程$\{N(t),t\geqslant0\}$称为具有速率$\lambda(\lambda>0)$的泊松过程，如果：

1. $N(0)=0$

2. $\{N(t),t\geqslant0\}$过程有平稳增量和独立增量

3. $P\{N(t+\Delta t)-N(t)=1\}=\lambda \Delta t+o(\Delta t)$

4. $P\{N(t+\Delta t)-N(t)\geqslant 2\}=o(\Delta t)$

**性质**

1. 任意长度为 t 的区间中的事件个数是均值为 $\lambda t$ 的泊松随机变量：$\large P\{N(t_0+t)-N(t_0)=n\}=P_n(t)=\cfrac{e^{-\lambda t}(\lambda t)^n}{n!}$
2. 设$T_n$为第n-1个事件与第n个事件间隔的时间，则到达间隔事件序列$\{T_n,n=1,2,...\}$是独立同分布的指数随机变量，$\large f(t)=\lambda\cdot e^{-\lambda t}$，均值为$1/\lambda$
3. 如果已知在$(0,t)$时间内发生n次事件，则n次事件的发生时间是独立同分布的均匀分布随机变量，均匀分布于(0,t)内
4. 如果已知在$(0,t_2)$时间内发生n次事件，则在$(0,t_1),t_1<t_2$时间内发生k次事件的概率为：$\large \binom{n}{k}(\cfrac{t_1}{t_2})^k(1-\cfrac{t_1}{t_2})^{n-k} $，服从二项分布
5. 第一个过程的第k个事件先于第二个过程的第一个事件的概率：$(\cfrac{\lambda_1}{\lambda_1+\lambda_2})^k$
6. 两个独立的参数为$\lambda_1,\lambda_2$的独立泊松过程，和是参数为$\lambda_1+\lambda_2$的泊松过程，差不是

**非时齐泊松过程**

计数过程$\{N(t),t\geqslant0\}$称为**强度函数**$\lambda(t)(t\geqslant0)$的非时齐泊松过程，如果：

1. $N(0)=0$

2. $\{N(t),t\geqslant0\}$过程有独立增量

3. $P\{N(t+\Delta t)-N(t)=1\}=\lambda(t) \Delta t+o(\Delta t)$

4. $P\{N(t+\Delta t)-N(t)\geqslant 2\}=o(\Delta t)$

起始为 $t_0$ 长度为 $t$ 的区间中的事件个数是均值为 $m(t_0+t)-m(t_0)$ 的泊松随机变量：$\large P\{N(t_0+t)-N(t_0)=n\}=\cfrac{e^{-[m(t_0+t)-m(t_0)]}[m(t_0+t)-m(t_0)]^n}{n!}$，其中 $\large m(t)=\int_0^t\lambda(y)dy$

**复合泊松过程**

过程$\{X(t),t\geqslant0\}$称为复合泊松过程，如果它可以表示为：$X(t)=\sum_{i=1}^{N(t)}Y_i$，其中$\{N(t),t\geqslant0\}$是一个泊松过程，$Y_i$是独立于$\{N(t),t\geqslant0\}$的一组独立同分布的随机变量

$E[X(t)]=\lambda tE[Y_i],\quad Var[X(t)]=\lambda tE[Y_i^2]$



## 排队过程

基本描述：A/R/S/N

- A：顾客到达系统的规律（典型为泊松到达）
- R：顾客在系统中接受服务的规律（典型为指数分布）
- S：系统中服务人员个数（典型为一个）
- N：系统中排队队长限制（典型为有限队长）

基本参数

- L：在排队系统的平均顾客数
- $L_Q$：在排队等候的平均顾客数
- W：顾客在系统中平均花费时间
- $W_Q$：顾客在排队等候时的平均时间

排队系统普适性Little定律：$L=\lambda W,\quad L_Q=\lambda W_Q$





# 最优化方法

最优化问题，即求一个多元函数在某个给定集合上的**极值**：
$$
min\,f(x)\\
s.t.\,x\in K
$$
其中 s.t.=subject to(受限于)，K 为**可行域**，f(x) 为**目标函数**，x为**决策变量**

- 线性规划和非线性规划：可行域是有限维空间中的一个子集
- 组合优化或网络规划：可行域中的元素有限
- 动态规划：可行域是一个依赖时间的决策序列
- 最优控制：可行域是无穷维空间中的一个连续子集




$$
\large{
min\,f(x)\\
s.t.\,h_i(x)=0,\quad i=1,...,l\\
\quad\quad\,\, g_i(x)\geqslant 0,\quad i=1,...,m
}
$$

其中$f(x),h_i(x),g_i(x)$都是定义在 $\R^n$上的连续可微的多元实值函数
$$
\large{
记\quad E=\{i:h_i(x)=0\},\quad I=\{i:g_i(x)\geqslant 0\}\\
\begin{cases}
无约束优化\quad E\bigcup I=\emptyset\\
约束优化
\begin{cases}
等式约束优化\quad E\not=\emptyset且 I=\emptyset\\
不等式约束优化\quad E=\emptyset且 I\not=\emptyset\\
线性规划\quad 目标函数和约束函数都是线性函数\\
二次规划\quad 目标函数是二次函数，约束函数是线性函数
\end{cases}
\end{cases}
}
$$



## 无约束优化问题

求无约束优化问题：$min\,f(x)$ 的局部极小值解 $x^*$

一阶必要条件：$g(x^*)=0$

二阶必要条件：$g(x^*)=0$ 且 $G(x^*)$ 是半正定矩阵

二阶充分条件：$g(x^*)=0$ 且 $G(x^*)$ 是正定矩阵

凸函数全局极小点的充要条件：$g(x^*)=0$



通常用**迭代法**求解无约束优化问题：$x_{k+1}=x_k+\alpha_kd_k$，其中$\alpha_k$为步长，$d_k$为搜索方向

$d_k$为**下降方向**的充分条件：$\large \exist\,\bar{\alpha},\,\forall\,\alpha\in(0,\bar{\alpha}]\,\&\,d_k\not=0,f(x_k+\alpha_kd_k)<f(x_k)$；当$f$一阶连续可微时，充要条件为：$\nabla f(x_k)^\top d_k<0$



迭代法**收敛性**：当初始点充分接近极小值点时，算法产生的点列才收敛于极小点，此时算法有局部收敛性；若对于任意初始点，算法产生的点列都收敛于极小点，此时算法有全局收敛性



**终止条件**：1. 位移的误差 2. 目标函数的误差 3. 目标函数的梯度的范数



## 线搜索技术

求解步长

令$\phi(\alpha)=f(x_k+\alpha d_k)$，通过搜索确定$\alpha_k$，使得 $\phi(\alpha_k)<\phi(0)$



**精确搜索：**求$\alpha_k$，使得 $\phi(\alpha_k)=min_{\alpha>0}\phi(\alpha)$；若$f(x)$连续可微，则 $g_{k+1}^\top d_k=0$

- 黄金分割法

  在搜索区间$[a_i,b_i]$中计算试探点：$p_i=a_i+0.382(b_i-a_i),\quad q_i=a_i+0.618(b_i-a_i)$，以及相应函数值 $\phi(p_i),\phi(q_i)$

  当$\phi(p_i)\leqslant \phi(q_i)$时，若$|q_i-a_i|<\epsilon$，则停止；否则令：$b_{i+1}=q_i,q_{i+1}=p_i,p_{i+1}=a_{i+1}+0.382(b_{i+1}-a_{i+1})$

  当$\phi(p_i)>\phi(q_i)$时，若$|p_i-b_i|<\epsilon$，则停止；否则令：$a_{i+1}=p_i,p_{i+1}=q_i,q_{i+1}=a_{i+1}+0.618(b_{i+1}-a_{i+1})$

  每次迭代搜索区间的收缩率是0.618，为线性收敛

- 抛物线法：





**非精确搜索：**选取$\alpha_k$，使得目标函数得到可接受的下降量

- Armijo准则

  给定$\beta\in(0,1),\sigma\in(0,0.5)$，找到满足不等式的最小负整数m：$f(x_k+\beta^md_k)\leqslant f(x_k)+\sigma \beta^mg_k^\top d_k$

  令步长 $\alpha_k=\beta^m$

- Wolfe准则

  给定$\rho\in(0,0.5),\sigma\in(\rho,0.5)$，找到满足不等式的$\alpha_k$：$f(x_k+\alpha_kd_k)\leqslant f(x_k)+\rho\alpha_kg_k^\top d_k,\quad g(x_{k+1})^\top d_k\geqslant\sigma g_k^\top d_k$

  

## 牛顿法

求解无约束最优化问题的更新量

**最速下降法（梯度下降法, GD）**

取方向$d_k=-g_k$，由线搜索技术确定步长因子$\alpha_k$，更新：$x_{k+1}=x_k+\alpha_kd_k$

收敛方向为锯齿状，最好时线性收敛

迭代若干次，每次使用全部样本计算步长

当每次只是用一个样本进行更新时，称为**随机梯度下降法(SGD)**



**牛顿法**

通过解线性方程组计算更新量$d_k$：$G_kd_k=-g_k$，更新：$x_{k+1}=x_k+d_k$

初始点需足够靠近极小点，否则可能不收敛

具有局部二阶收敛性



**阻尼牛顿法**

通过解线性方程组计算更新量$d_k$：$G_kd_k=-g_k$，用Armijo准则求得步长$\alpha_k$，更新：$x_{k+1}=x_k+\alpha_kd_k$

改进牛顿法，可在大范围收敛



**拟牛顿法**

使用另一个矩阵近似海森矩阵以简化计算量

记$y_k=g_{k+1}-g_k,\delta_k=x_{k+1}-x_k$，则有拟牛顿条件$\delta_k=G_k^{-1}y_k$

有DFP算法，BFGS算法，Broyden类算法



## 非线性最小二乘问题

通常用来求解残差最小问题，平方因为可导且次方低

记$F(x)=(F_1(x),F_2(x),...,F_m(x))^\top$，非线性最小二乘问题为：$\min_x\, f(x)=\cfrac{1}{2}||F(x)||_2^2$

目标函数梯度为：$g(x)=J(x)^\top F(x)=\sum_{i=1}^m F_i(x)\nabla F_i(x)$

目标函数Hesse矩阵为：$G(x)=J(x)^\top J(x)+S(x)=J(x)^\top J(x)+\sum_{i=1}^m F_i(x)\nabla^2 F_i(x)$

带入牛顿法中得到迭代式：$x_{k+1}=x_k-(J_k^\top J_k+S_k)^{-1}J_k^\top F(x_k)$



**Gauss-Newton法**

将上式中的$S(x)$忽略，得到迭代式：$x_{k+1}=x_k+d_k^{GN}$，其中Gauss-Newton方向为：$d_k^{GN}=-[J_k^\top J_k]^{-1}J_k^\top F(x_k)$

要求$\nabla F(x)$是列满秩的，以保证方向为下降方向

可结合Wolfe规则计算步长



**Levenberg-Marquardt法**

通过求解下述模型来获取搜索方向：$d_k=\arg \min_d\,\,||J_kd+F_k||^2+\mu_k||d||^2,\,\,\mu_k>0$

步骤：

1. 取 $\beta,\sigma\in(0,1),\mu_0>0$
2. 若 $g(x_k)=0$则停止
3. 求解方程组得$d_k$：$(J_k^\top J_k+\mu_kE)d_k=-J_k^\top F_k$
4. 用Armijo搜索步长$\alpha_k$
5. 更新：$x_{k+1}=x_k+\alpha_kd_k$，$\mu_{k+1}=\begin{cases}0.1\mu_k,\,\,\eta_k>0.75\\ \mu_k,\,\,\,\,\,\,\,\,\,0.25\leqslant \eta_k\leqslant0.75\\ 10\mu_k,\,\,\,\,\eta_k<0.25 \end{cases}$，$\eta_k=\cfrac{\Delta f(d_k)}{\Delta q(d_k)}=\cfrac{f(x_{k+1})-f(x_k)}{(J_k^\top F_k)^\top d_k+\frac{1}{2}d_k^\top(J_k^\top J_k)d_k}$



## 约束优化问题的最优性条件

约束优化问题的最小值一般在边界上取到

**等式约束问题**
$$
\min_{x\in\R}\quad f(x)\\
s.t.\quad h_i(x)=0\\
L(x,\lambda)=f(x)-\sum_{i=1}^m\lambda_ih_i(x)
$$
**拉格朗日定理：**取极小值的**一阶必要条件**，即**KT(Kuhn-Tucker)**条件

设$x^*$是上述问题的局部极小值点，$f(x)$和$h_i(x)$在$x^*$的某邻域连续可微。若向量组$\nabla h_i(x^*)$线性无关，则存在乘子向量$\lambda^*$，使得 $\nabla_x L(x^*,\lambda^*)=0$

对于$\forall x\in D$，有：$L(x^*,\lambda^*)=f(x^*)\leqslant f(x)=f(x)-(\lambda^*)^\top h(x)=L(x,\lambda^*)$，因此上述问题可转化为：
$$
\min_x\quad L(x,\lambda^*)\\s.t.\quad h_i(x)=0
$$


**不等式约束问题**
$$
\min_{x\in\R} \quad f(x)\\
s.t.\quad g_j(x)\geqslant0\\
L(x,\mu)=f(x)-\sum_{j=1}^n\mu_jg_j(x)\\
$$
有效约束：可行点 $\bar{x}$ 使得 $g_i(\bar{x})=0$

非有效约束：可行点 $\bar{x}$ 使得 $g_i(\bar{x})>0$



KT条件：

设$x^*$是上述问题的局部极小值点，有效约束集 $I(x^*)=\{i|g_i(x^*)=0\}$，$f(x)$和$g_i(x)$在$x^*$处可微。若向量组$\nabla g_i(x^*)(i\in I(x^*))$线性无关，则存在乘子向量$\mu^*$，使得： $\begin{cases}\nabla_x L(x^*,\mu^*)=0\\g_i(x^*)\geqslant0,\mu_i^*\geqslant0,\mu_i^*g_i(x^*)=0 \end{cases}$



**一般约束问题**

考虑函数f(x)在约束g(x)下求极值的问题，有如下结论：

- 对于约束曲面上的任一点$x$，该点的梯度$\nabla g(x)$正交于约束曲面
- 在最优点$x^*$，目标函数在该点的梯度$\nabla f(x^*)$正交于约束曲面



最优化问题，广义拉格朗日函数，KT条件如下：
$$
\large{
\min_{x\in\R}\quad f(x)\\
s.t.\quad h_i(x)=0，g_j(x)\geqslant0\\
L(x,\lambda,\mu)=f(x)-\sum_{i=1}^l\lambda_ih_i(x)-\sum_{j=1}^m \mu_jg_j(x)\\
KT:\begin{cases} 
\nabla_x L(x,\lambda,\mu)=0\\
h_i(x)=0\\
g_j(x))\geqslant0\\
\mu_j \geqslant 0\\
\mu_jg_j(x)=0\\
\end{cases}
}
$$
$x^*$为KT点，$(x^*(\lambda^*,\mu^*))$为KT对，$(\lambda^*,\mu^*)$为拉格朗日乘子

一般上述问题的KT点不一定是局部最小点，但对于凸优化问题，KT点、局部极小点、全局极小点三者等价



**凸优化问题**

$f(x)$ 和 $-g(x)$ 是连续可微凸函数，$h(w)$是线性函数

当$f(x)$是二次函数且$g(x)$是仿射函数时，上述问题成为**凸二次规划问题**



**鞍点**

对于一般约束优化问题，若存在$x^*$和$(\lambda^*,\mu^*)$，满足 $L(x^*,\lambda,\mu)\leqslant L(x^*,\lambda^*,\mu^*)\leqslant L(x,\lambda^*,\mu^*),\quad \forall(x^*,\lambda,\mu)\in\R^n\times \R^l\times \R_+^m$，则$(x^*,\lambda^*,\mu^*)$为约束优化问题的拉格朗日函数的鞍点

一般约束优化问题，鞍点是KT点的充分条件；凸优化问题，鞍点是KT点的充要条件



**拉格朗日对偶性**
$$
\large{
\max_{x\in\R}\quad \theta(\lambda,\mu)\\
s.t.\quad \lambda\in\R^l,\mu\in\R_+^m\\
\theta(\lambda,\mu)=\inf_{x\in\R}L(x,\lambda,\mu)\\
L(x,\lambda,\mu)=f(x)-\lambda^\top H(x)-\mu^\top G(x)
}
$$
$\theta(\lambda,\mu)$是凹函数；

代入对应可行解有弱对偶定理：$\theta(\bar\lambda,\bar\mu)\leqslant f(\bar x)$



将原最优化问题，转化为求广义拉格朗日函数的极小极大问题，再转化为极大极小问题的对偶问题，两个问题在一定条件下等价，需要满足KT条件



## 罚函数法

求解约束优化问题的一种方法



**外罚函数法**

求解一般约束优化问题，构造罚函数：$\large \bar P(x)=\sum_{i=1}^l h_i^2(x)+\sum_{i=1}^m[\min\{0,g_i(x)\}]^2$，增广目标函数：$\large P(x,\sigma)=f(x)+\sigma\bar P(x)$

转化为求解优化问题：
$$
\large{
\min P(x,\sigma_k)\\
\{\sigma_k\in\R_+\},\sigma\rightarrow +\infty
}
$$
当 $\sigma\rightarrow +\infty$ 时，$x(\sigma)\rightarrow x^*$，但是是从可行域外部趋近，因此称为外点法

简单函数方法：令$\cfrac{\part P(x,\sigma)}{\part x_i}=0$，得$x_i(\sigma)$；令$\sigma\rightarrow +\infty$，得$x(\sigma)\rightarrow x^*$

数值方法步骤：

1. 给定初始点$x_0$，终止误差$\epsilon$，$\sigma_1>0,\eta>1$
2. 以$x_{k-1}$为初始点求解无约束子问题：$\min_x P(x,\sigma_k)=f(x)+\sigma_k\bar P(x)$，得极小点 $x_k$
3. 若$\sigma_k\bar P(x_k)\leqslant \epsilon$，停算，输出
4. 更新：$\sigma_{k+1}=\eta\sigma_k,k=k+1$

缺点：1. $x_k$往往是不可行点；2. 罚参数$\sigma_k$选取困难；3. $\bar P(x)$一般不可微，收敛速度慢



**内点法**

求解不等式约束优化问题；迭代值一直在可行域内部，靠近边界时，增广目标函数值骤然增大，阻止迭代点穿越边界

障碍函数（罚函数）可取倒数和：$\large \bar H(x)=\sum_{i=1}^m\cfrac{1}{g_i(x)}$，或对数和：$\large \bar H(x)=-\sum_{i=1}^mln[g_i(x)]$

增广目标函数：$\large H(x,\sigma)=f(x)+\tau\bar H(x)$，当 $\tau\rightarrow 0$ 时，$x(\tau)\rightarrow x^*$，

数值方法步骤：

1. 给定初始点$x_0$，终止误差$\epsilon$，$\tau_1>0,\gamma\in(0,1)$
2. 以$x_{k-1}$为初始点求解无约束子问题：$\min_x H(x,\tau_k)=f(x)+\tau_k\bar H(x)$，得极小点为 $x_k$
3. 若$\tau_k\bar H(x_k)\leqslant \epsilon$，停算，输出
4. 更新：$\tau_{k+1}=\eta\tau_k,k=k+1$

结构简单，一直在可行域内部，但随着迭代进行，罚参数越来越小，使得无约束子问题的求解在数值上实现困难；另外要求初始点为严格的可行点

求一般约束优化问题时，可结合内点法，构造混合增广目标函数：$H(x,\mu)=f(x)+\cfrac{1}{2\mu}\sum_{i=1}^lh_i^2(x)+\mu\bar H(x)$



**乘子法(PH法)**

考虑求解等式约束优化问题：$\min_x L(x,\lambda^*)， s.t. h_i(x)=0$，使用外罚函数法构造增广目标函数：$\psi(x,\lambda^*,\sigma)=L(x,\lambda^*)+\cfrac{\sigma}{2}||h(x)||_2^2$；由于$\lambda^*$事先不知道，可用迭代法；

当$\{h(x_k)\}\rightarrow0$，$\sigma$足够大时，$\{\lambda_k\}$收敛，得到原等式约束优化问题的KT对

数值方法步骤：

1. 给定初始点$x_0$，终止误差$\epsilon$，$\lambda_1\in\R^l,\sigma_1>0,v\in(0,1),\eta>1$
2. 以$x_{k-1}$为初始点求解无约束子问题：$\large \min_x \psi(x,\lambda_k,\sigma_k)=f(x)-\lambda_k^\top h(x)+\cfrac{\sigma}{2}||h(x)||_2^2$，得极小点为 $x_k$
3. 若$||h(x_k)||\leqslant \epsilon$，停算，输出
4. 更新罚参数：$||h(x_k)||\geqslant v||h(x_{k-1})||?\,\,\sigma_{k=1}=\eta\sigma_k:\sigma_{k=1}=\sigma_k$
5. 更新乘子向量：$\lambda_{k+1}=\lambda_k-\sigma_kh(x_k),k=k+1$

**PHR法：**求一般约束优化问题时，引入辅助变量将不等式转为等式：

1. 给定初 始点$x_0$，终止误差$\epsilon$，$\lambda_1\in\R^l,\mu_1\in\R^m,\sigma_1>0,v\in(0,1),\eta>1$
2. 以$x_{k-1}$为初始点求解无约束子问题：$\large \min_x \psi(x,\lambda_k,\mu_k,\sigma_k)=f(x)-\lambda_k^\top h(x)+\cfrac{\sigma}{2}||h(x)||_2^2+\cfrac{1}{2\sigma}\sum_{i=1}^m([\min\{0,\sigma g_i(x)-\mu_i\}]^2-\mu_i^2)$，得极小点为 $x_k$
3. 若$\beta_k\leqslant \epsilon$，其中 $\large \beta_k=(||h(x_k)||_2^2+\sum_{i=1}^m[\min\{g_i(x_k),\cfrac{(\mu_k)_i}{\sigma}\}]^2)^{1/2}$，停算，输出
4. 更新罚参数：$\beta_k\geqslant v\beta_{k-1}?\,\,\sigma_{k=1}=\eta\sigma_k:\sigma_{k=1}=\sigma_k$
5. 更新乘子向量：$(\lambda_{k+1})_i=(\lambda_k)_i-\sigma_kh_i(x_k),\quad (\mu_{k+1})_i=\max\{0,(\mu_k)_i-g_i(x_k)\},\quad k=k+1$






























