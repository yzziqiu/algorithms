# applied-sort
# 1.给定一个列表判断里面是否有重复元素

from collections import Counter
def dupli_1(A):
    # set
    if len(A) != len(set(A)):
        print("duplicate!")
    else:
        print("safe")

def dupli_2(A):
    # Counter
    coun = Counter(A)
    key = coun.most_common(1)
    if key[0][1] > 1:
        print("duplicate!")
    else:
        print("safe")

if __name__ == '__main__':
    num_list=[[1,2,3,4],[6,7,8],[4,5,6,6,6]]
    #for one_list in num_list:
        #print (one_list)
        #dupli_1(one_list)
        #dupli_2(one_list)

# 2.Merge Sorted Array 合并两个有序数组
# O(M+N) 时间 O(1) 空间
# 从后往前填充即可

def merge(a,b):
    counta=countb=0
    #分别记录两个数组遍历到哪个位置了
    c = []
    for i in range(counta,len(a)):
        for j in range(countb,len(b)):
            print (j,b[j])
            if(b[j] <= a[i]):
                c.append(b[j])
                countb=countb+1
                #append了b[j],那么b数组的遍历的记录应该自增
            else:
                c.append(a[i])
                counta = counta+1
                #append了a[i],那么a数组的遍历的记录应该自增
                break#为啥要break？因为到此位置，说明b数组不能继续往下遍历了，该遍历a了

    #现在就需要吧两个数组中剩余的元素依次append到c中即可
    if (counta < len(a)):
        for i in range(counta,len(a)):
            c.append(a[i])
    if (countb < len(b)):
        for j in range(countb,len(b)):
            c.append(b[j])
    return c
arr1 = [3,4,5,6]
arr2 = [1,2,3]
# print(merge(arr1,arr2))

# 3.三色排序
# 有一个只由0，1，2三种元素构成的整数数组，请使用交换、原地排序而不是使用计数进行排序。
class ThreeColor:
    def sortThreeColor(self, A, n):
        zindex = -1
        tindex = n
        i = 0
        while i < tindex:
            if A[i] == 0:
                zindex += 1
                A[zindex], A[i] = A[i], A[zindex]
                i += 1
            elif A[i] == 1:
                i += 1
            else:
                tindex -= 1
                A[tindex], A[i] = A[i], A[tindex]
            #print("i = " + str(i) + "  ->  " + str(A))
        return A

if __name__ == '__main__':
    three = ThreeColor()
    #print(three.sortThreeColor([1,2,0,2],4))

# 4. 有序矩阵查找
# 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
# 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
def search(array, target):
    m = len(array) - 1
    i = 0
    while m >= 0 and i < len(arr[0]):
        if array[m][i] > target:
            m -= 1
        elif array[m][i] < target:
            i += 1
        else:
            return target
    return 0

arr = [[1,2,3],[4,5,10,12]]
tar = 6
# print(search(arr,tar))

# 5.最短子数组
# 给定整数数组，找到一个最短的连续的未按照升序排序的最短子数组，返回子数组的长度。
# 先将数组排序赋给一个新的数组，通过两个数组之间的比较，
# 第一个和最后一个元素不同的位置索引即为子数组的界限。
# 先将数组排序，后用zip(old, new)来比较排序前后数组元素之间是否一一对应相等；
# 数组总长度减去正序的一个为False的位置和逆序第一个为False的位置。

start=0
end=0
abstractstart=0 #子数组起始位置
abstractend=0 #子数组结束为止

a = ['testing','pattern']
b = ['hello','this','is','a','testing','page','description','testing','pattern','all','is','about','testing']
target=len(b)
#子数组长度
def IsContainAll(): #判断b子数组是否包含a所有元素
    if len(a)>end-start+1:
        return False
    sameCount=0
    for i in range(0,len(a)):
        for j in range(start,end+1):
            if a[i]==b[j]:
                sameCount+=1
                break

    if sameCount==len(a):
        return True
    else:
        return False

while(True):
    while(not IsContainAll() and end<len(b)-1):#如果没有包含且end没有到达元素末尾，则end+1
        end+=1
    while IsContainAll():
        if end-start<target: #包含所有元素组成的串小于之前的串长度，则更新串长度
            target=end-start+1
            abstractstart=start
            abstractend=end
        start+=1 #从start+1处重新遍历
    if end>=len(b)-1:
        break
#print(abstractstart)
#print(abstractend)
#print(target)

# 6.相邻最大差值
# 给定一个整数数组A和数组的大小n，请返回最大差值。保证数组元素个数大于等于2小于等于500。
# 使用桶排序，时间复杂度为O(n)

# 找出最大值和最小值。
# 生成一个最大值-最小值的区间 比如最大值9，最小值3，那就需要7个桶
# 往里面填
# 查找空桶，最多的即为最大差值。
def findMaxDivision(A, n):
    minn = min(A)
    maxx = max(A)
    # 生成桶
    res = [0 for i in range(maxx - minn + 1)]
    # 填桶
    for i in range(n):
        res[A[i] - minn] += 1
    count = 0
    num = -0x3f3f3f3f
    for i in range(len(res)):
        if res[i] == 0:
            # 如果说当前的桶为空，则记录下来连续的空桶数
            count += 1
        else:
            if num < count:
                num = count
            count = 0
        # 为何加1？举例如下：最大值为9，最小值为3，中间有5个空桶，但差值应为6
    return num + 1
print(findMaxDivision([9,3,1,10],4))
