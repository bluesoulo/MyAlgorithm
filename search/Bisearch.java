import java.util.*;
/**
 * @author zhangjinjie <zhangjinjie@kuaishou.com>
 * Created on 2023-07-02
 */
public class Main {

    public static int lbiSearch(int[] nums, int target, int end) {
        int l = 0, r = end;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    public static int rbiSearch(int[] nums, int target, int end) {
        int l = 0, r = end;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }

    public static long getSegmentNum(int[] array, int l) {
        long sum = 0;
        for (int t: array
        ) {
            sum += (t / l);
        }
        return sum;
    }

    public static boolean judge(int[] array, int maxLength, int sum) {
        int t = 0, num = 0;
        for (int i = 0; i < array.length; i++) {
            int v = array[i] - t;
            if (v > maxLength) {
                if (v % maxLength == 0) {
                    num += v / maxLength - 1;
                } else {
                    num += v / maxLength;
                }
            }
            t = array[i];
        }
        return num <= sum;
    }

    public static int search(int[] array, int left, int right, int sum) {
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (judge(array, mid, sum)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int distance = scanner.nextInt();
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] array = new int[n + 1];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        Arrays.sort(array);
        array[n] = distance;
        System.out.println(search(array, 1, distance, m));
    }
}
