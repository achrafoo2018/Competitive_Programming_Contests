n , m = [int(i) for i in input().split(" ")]
arr = [int(i) for i in input().split(" ")]
MOD = 10**9+7

def check(mid, array, n, K):
    count = 0
    sum_ = 0
    for i in range(n):
         
        # If individual element is greater
        # maximum possible sum_
        if (array[i] > mid):
            return False
 
        # Increase sum_ of current sub - array
        sum_ += array[i]
 
        # If the sum_ is greater than
        # mid increase count
        if (sum_ > mid):
            count += 1
            sum_ = array[i]
    count += 1
 
    # Check condition
    if (count <= K):
        return True
    return False
 
# Function to find maximum subarray sum
# which is minimum
def solve(array, n, K):
   
    start = max(array) #Max subarray sum, considering subarray of length 1
    end = 0
 
    for i in range(n):
        end += array[i] #Max subarray sum, considering subarray of length n
 
    # Answer stores possible
    # maximum sub array sum
    answer = 0
    while (start <= end):
        mid = (start + end) // 2
 
        # If mid is possible solution
        # Put answer = mid;
        if (check(mid, array, n, K)):
            answer = mid
            end = mid - 1
        else:
            start = mid + 1
 
    return answer


print(solve(arr, n, m))