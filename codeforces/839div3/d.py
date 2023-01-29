# Read t, the number of test cases
t = int(input())

# Process each test case
for _ in range(t):
  # Read n and a
  n = int(input())
  a = list(map(int, input().split()))

  # Set x to be the average of a1 and an
  x = (a[0] + a[-1] + 1) // 2

  # Apply the operation |ai - x| to each element of a
  for i in range(n):
    a[i] = abs(a[i] - x)

  # Check if the resulting array is sorted
  is_sorted = True
  for i in range(1, n):
    if a[i] < a[i-1]:
      is_sorted = False
      break

  # Print the result
  if is_sorted:
    print(x)
  else:
    print(-1)
