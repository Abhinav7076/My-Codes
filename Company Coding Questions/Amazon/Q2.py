def find element (nums, target): 
	length len (nums)

	st = 0

	ed= length-1

	while sted:

		mid (st + ed + 1) // 2 
		if nums [mid] [1] > target:
			ed mid-1
		else:
			st = mid
	return nums [st]



def UptimalUtilization (a, b, target):

	a.sort (key-lambda x:x[1]) 
	b.sort (key-lambda x:x[1])
	len1 = len (a)
	len2 = len (b) 
	curval=0
	res []

	for idx1, num1 in a:

		idx2, num2= find_element (b, target-num1)

		if num1 + num2 <= target:

			print (numl+num2)

			if curval< num1 + num2: 
				curval numl + num2

				res= [[idx1, idx2]] 
			elif curval==numl + num2:
				res.append([idxl, idx2])

	return res


a = [[1, 2], [2, 4], [3, 6]]

b [[1, 2]]

target 7 
print (UptimalUtilization (a, b, target))

#java

public class Solution {
    public List<int[]> optimizeMemoryUsage(int[] foregroundTasks, int[] backgroundTasks, int K) {
		List<int[]> result = new ArrayList();
		TreeMap<Integer, List<Integer>> foregroundMemToIds = new TreeMap();
		
		for (int i = 0; i < foregroundTasks.length; ++i) {
		    int mem = foregroundTasks[i];
		    if (mem > K)
		        continue;
		    foregroundMemToIds.putIfAbsent(mem, new ArrayList());
		    foregroundMemToIds.get(mem).add(i);
		}
		foregroundMemToIds.put(0, new ArrayList());
		foregroundMemToIds.get(0).add(-1);
		
		int maxMem = foregroundMemToIds.lastKey();
		for (int foregroundId : foregroundMemToIds.get(maxMem)) {
		    result.add(new int[] { foregroundId,  -1 });
		}
		
		for (int i = 0; i < backgroundTasks.length; ++i) {
		    int backgroundMem = backgroundTasks[i];
		    Integer foregroundMem = foregroundMemToIds.floorKey(K - backgroundMem);
		    if (foregroundMem == null) 
		        continue;
		    int sumMem = foregroundMem + backgroundMem;
		    if (sumMem > K || sumMem < maxMem) 
		        continue;
		        
		    if (sumMem > maxMem) {
		        result = new ArrayList();
		        maxMem = sumMem;
		    }
		    
		    for (int foregroundId : foregroundMemToIds.get(foregroundMem))
		        result.add(new int[] { foregroundId,  i });
		}

		return result;
    }
}