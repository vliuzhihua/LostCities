##note:
- 在项目中，我们使用&引用来传递不会在函数中改变的参数，当然加个const的。使用*指针传参来表示会被改变的参数。

##2015/11/6
- 今天中午试了一下测试程序，运行10次发现总是一个人获胜，故而认为是update有问题，修改即好。然后配置了release版本，快速测试100次输赢比例之类的。
- 然后呢认为结构上来说player置身于game system之外了貌似，这就是为什么updateStatus都需要传递进去Player数据结构的原因。要改，这不好。关于测试程序是否到位，看你觉得呢。
