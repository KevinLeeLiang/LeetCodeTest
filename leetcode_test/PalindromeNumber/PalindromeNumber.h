#pragma once
/**
 * @brief     - 可以利用取整和取余来获得想要的数字，比如 1221 这个数字，
                如果 计算 1221 / 1000， 则可得首位1， 如果 1221 % 10， 
                则可得到末尾1，进行比较，然后把中间的 22 取出继续比较
 * @param x  {int} 待检查整数
 * @return   {bool}是回文书返回true，否则返回false
*/
bool PalindromeNumber1(int x) {
  if (x < 0) return false;
  int div = 1;
  while (x / div >= 10) div *= 10;
  while (x > 0) {
    int left = x / div;
    int right = x % 10;
    if (left != right) return false;
    x = (x % div) / 10;
    div /= 100;
  }
  return true;
}

/**
 * @brief     - 首先判断x是否为负数，这里可以用一个小 trick，因为整数的最高位不能是0，
                所以回文数的最低位也不能为0，数字0除外，所以如果发现某个正数的末尾是0了，
                也直接返回 false 即可。好，下面来看具体解法，要验证回文数，那么就需要看前后半段是否对称，
                如果把后半段翻转一下，就看和前半段是否相等就行了。所以做法就是取出后半段数字，进行翻转，
                具体做法是，每次通过对 10 取余，取出最低位的数字，然后加到取出数的末尾，
                就是将 revertNum 乘以 10，再加上这个余数，这样翻转也就同时完成了，每取一个最低位数字，x都要自除以 10。
                这样当 revertNum 大于等于x的时候循环停止。
                由于回文数的位数可奇可偶，如果是偶数的话，那么 revertNum 就应该和x相等了；
                如果是奇数的话，那么最中间的数字就在 revertNum 的最低位上了，除以 10 以后应该和x是相等的
 * @param x  {int} 待检查整数
 * @return   {bool}是回文书返回true，否则返回false
*/
bool PalindromeNumber2(int x) {
  if (x < 0 || (x % 10 == 0 && x != 0)) return false;
  int revertNum = 0;
  while (x > revertNum) {
    revertNum = revertNum * 10 + x % 10;
    x /= 10;
  }
  return x == revertNum || x == revertNum / 10;
}