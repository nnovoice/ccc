import java.util.Scanner;

public class Solution {
  public boolean isPossible(int a, int b, int c, int d, int nCharge) {
      int xDiff = c - a;
      int yDiff = d - b;

      xDiff = (xDiff < 0) ? (0 - xDiff) : xDiff;
      yDiff = (yDiff < 0) ? (0 - yDiff) : yDiff;

      int minChargeNeeded = xDiff + yDiff;

      // not enough charge?
      if (nCharge < minChargeNeeded) return false;

      // both are even?
      if (nCharge % 2 == 0 && minChargeNeeded % 2 == 0) return true;

      // both are odd?
      if (nCharge % 2 != 0 && minChargeNeeded % 2 != 0) return true;

      return false;
  }

  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int b = in.nextInt();
    int c = in.nextInt();
    int d = in.nextInt();
    int nCharge = in.nextInt();

    Solution sol = new Solution();
    boolean isPossible = sol.isPossible(a, b, c, d, nCharge);
    char cPossible = isPossible ? 'Y' : 'N';
    System.out.println(cPossible);
  }
}
