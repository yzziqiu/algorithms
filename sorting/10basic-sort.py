# 1.bubble-sort
# 反复交换相邻的未按次序排列的元素。即把小的元素往前调，或者把大的元素往后调


def bubble_sort(A):
    n = len(A)
    for i in range(0, n):
        for j in range(i+1,n):
            if A[i] > A[j]:
                 A[i], A[j] = A[j], A[i]
    return A


arr = [4,5,2,3,1]
# print (bubble_sort(arr))

# 空间复杂度：O(1), in-place排序
# 最差/平均/最优时间复杂度：O(n^2)
# 相同元素的前后顺序不会改变，因此是一种稳定的排序算法。

# 2.selection sort
# 为每个位置选择当前元素最小的。即，首先找出A中的最小元素并将其与A[0]中的元素进行交换。接着，找出A中次最小元素并将其与A[1]中的元素进行交换。对A中前n-1个元素按该方式继续。
# find max
def selection_sort(A):
    n = len(A)
    for i in range(0, n):
        min = i
        for j in range(i+1, n):
            if A[j] > A[min]:
                min = j
        A[min], A[i] = A[i], A[min]
    return A

#print (selection_sort(arr))

# 空间复杂度：O(1), in-place排序
# 时间复杂度：O(n^2)
# 记录最小/大那个元素的下标，而不是值。
# 相同元素的前后顺序可能改变，因此是不稳定的排序算法

# 扫描数组，每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中的适当位置，直到全部记录插入完成为止。


# 3.insertion_sort

#空间复杂度：O(1), in-place排序
#时间复杂度：O(n^2)

def insertion_sort(A):
    # 插入排序
    n = len(A)
    for i in range(1, n):
        key = A[i]
        j = i - 1
        while j >= 0:
            if A[j] > key:
                A[j + 1] = A[j]
                A[j] = key
            j -= 1
    return A
#print(insertion_sort(arr))

#只要循环到一个小于或等于key值的数就说明找到key值的位置了。此时需要结束循环
#用key值去比较，而不是用相邻的两个值做比较
#当n很小的时候效率较高，当n很大的时候，不适用
#一种稳定的算法


# 4.merge-sort
#分解：分解待排序的n个元素的序列成各具n/2个元素的两个子序列
#解决：使用归并排序递归地排序两个子序列
#合并(MERGE)：合并两个已排序的子序列以产生已排序的答案

def merge(left, right):
    i, j = 0, 0
    result = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result

def merge_sort(lists):
    # 归并排序
    if len(lists) <= 1:
        return lists
    num = len(lists) // 2 # rounded down //
    left = merge_sort(lists[:num])
    right = merge_sort(lists[num:])
    return merge(left, right)

#print(merge_sort(arr))

#最差/平均时间复杂度：O(nlogn)；最优时间复杂度：O(n)
#最差空间复杂度：O(n)

#归并的时候，计算出来的n1, n2是真实的L数组和R数组的长度。如果使用哨兵，申请L数组和R数组的时候，需要给哨兵申请一个位置，也就是说，需要申请的长度比实际上多1，即n1+1, n2+1
#归并的时候，将左右数组的元素放到目标（也是源）数组排序后的位置时，循环用目标数组的位置作为继续条件。也就是说，只要目标数组的位置占满了，就可以退出比较循环。
#归并的时候，若不使用哨兵，注意主循环结束的条件是，左数组、右数组或者目标数组有一个到达了数组的最后一个元素。
#这种排序方法比较占用内存，却是一种效率高且稳定的算法


# 5.count——sort
# 计数排序在输入n个0到k之间的整数时，时间复杂度最好情况下为O(n+k),最坏情况下为O(n+k),平均情况为O(n+k),空间复杂度为O(n+k)，计数排序是稳定的排序。
# 找出待排序的数组中最大和最小的元素
# 统计数组中每个值为i的元素出现的次数，存入数组 C 的第 i 项
# 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
# 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
def count_sort(A):
    min = 2147483647
    max = 0
    for x in A:
        if x < min:
            min = x
        if x > max:
            max = x
    count = [0] * (max-min+1)
    for index in A:
        count[index-min] += 1
    index = 0
    for a in range(max-min+1):
        for c in range(count[a]):
            A[index] = a+min
            index += 1
    return A
#print(count_sort(arr))

# 6. radix-sort
# 首先按照最低有效位进行排序，最低位优先(Least Significant Digit first)法，简称LSD法
# 先从kd开始排序，再对kd-1进行排序，依次重复，直到对k1排序后便得到一个有序序列。

def radix_sort(A):
    k = len(str(max(A)))        # k获取最大位数
    for k in range(k):     # 遍历位数，从低到高
        s=[[] for i in range(10)]       # 生成存放数的十个桶
        for i in A:     # 遍历元素
            s[i//(10**k)%10].append(i)      #分桶
        A=[a for b in s for a in b]     # 合并桶
    return A

#print(radix_sort(arr))

## 7. shell-sort
# 先取一个小于n的整数d1作为第一个增量，把文件的全部记录分组。
# 所有距离为d1的倍数的记录放在同一个组中。先在各组内进行直接插入排序；
# 然后，取第二个增量d2<d1重复上述的分组和排序，直至所取的增量
def shell_sort(list):
	length = len(list)
	dist = length // 2
	while dist > 0:
		for i in range(dist,length):
			temp = list[i]
			j = i
			while j >= dist and temp < list[j-dist]:
				list[j] = list[j-dist]
				j -= dist
			list[j] = temp
		dist //= 2
	return list
#print(shell_sort(arr))

## 8. quick-sort
# 随意选择一个数字作为基准，比基准数字大的在右，比基准数字小的在左。
def quick_sort(A,i,j):#快排总函数
                #制定从哪开始快排
    if i < j:
        base = qs(A,i,j)
        quick_sort(A,i,base)
        quick_sort(A,base+1,j)
    return A
def qs(A,i,j):#快排排序过程
    base = A[i]
    while i < j:
        while i < j and A[j] >= base:
            j -= 1
        while i < j and A[j] < base:
            A[i] = A[j]
            i += 1
            A[j] = A[i]
        A[i] = base
    return i

#print(quick_sort(arr,0,len(arr)-1))

## 9.heap_sort
# 创建最大堆:将堆所有数据重新排序，使其成为最大堆
# 最大堆调整:作用是保持最大堆的性质，是创建最大堆的核心子程序
# 堆排序:移除位在第一个数据的根节点，并做最大堆调整的递归运算


def heap_sort(list):
	length_list = len(list)
	first = int(length_list/2 - 1)
	for start in range(first,-1,-1):
		max_heapify(list,start,length_list-1)
	for end in range(length_list-1,0,-1):
		list[end],list[0] = list[0],list[end]
		max_heapify(list,0,end-1)
	return list

def max_heapify(ary,start,end):
	root = start
	while True:
		child = root*2 + 1
		if child > end:
			break
		if child + 1 <= end and ary[child]<ary[child+1]:
			child = child + 1
		if ary[root]<ary[child]:
			ary[root],ary[child]=ary[child],ary[root]
			root=child
		else:
			break

# print(heap_sort(arr))

# 10.bucket-sort
# 设待排序序列的元素取值范围为0到m，则我们新建一个大小为m+1的临时数组并把初始值都设为0，遍历待排序序列，把待排序序列中元素的值作为临时数组的下标，找出临时数组中对应该下标的元素使之+1；
# 然后遍历临时数组，把临时数组中元素大于0的下标作为值按次序依次填入待排序数组，元素的值作为重复填入该下标的次数，遍历完成则排序结束序列有序。
# 时间复杂度为O(n)

def bucket_sort(lst):
    buckets = [0] * ((max(lst) - min(lst))+1)
    for i in range(len(lst)):
        buckets[lst[i]-min(lst)] += 1
    res=[]
    for i in range(len(buckets)):
        if buckets[i] != 0:
            res += [i+min(lst)]*buckets[i]
    return res
    
print(bucket_sort(arr))
