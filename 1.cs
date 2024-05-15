int[] arr = [1, 2, 3, 4, 5, 6, 7];
const int targetSum = 7;

var indexMap = new Dictionary<int, int>();

for (var i = 0; i < arr.Length; ++i)
{
    var complement = targetSum - arr[i];
    if (indexMap.TryGetValue(complement, out var foundIndex))
    {
        Console.WriteLine($"{foundIndex} -> {i}");
        return;
    }

    indexMap[arr[i]] = i;
}

Console.WriteLine("No pair found that sums up to the target.");