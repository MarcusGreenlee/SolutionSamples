using System;
using System.Collections;

namespace ProcessIntArray
{
    internal class Program
    {
        static int findMedian(int[] nums) 
        {
            int median;
            Array.Sort(nums);

            // If we have an even number of samples, then take the average
            if (nums.Length % 2 == 0)
            {
                int rightIndex = nums.Length / 2;
                int leftIndex = rightIndex - 1;

                median = (nums[leftIndex] + nums[rightIndex]) / 2;
            }
            else
            {
                median = nums[nums.Length / 2];
            }

            return median;
        }

        static void Main(string[] args)
        {
            int[] arrToSortEven = { 10, 99, 3, 19, 42, 17, 38, 6, 55, 21};
            int[] arrToSortOdd = { 10, 99, 3, 19, 42, 17, 38, 6, 55, 21, 66};

            int maxValue = arrToSortEven.Max();
            int minValue = arrToSortEven.Min();
            int medianEven = findMedian(arrToSortEven);
            int medianOdd = findMedian(arrToSortOdd);

        }
    }
}