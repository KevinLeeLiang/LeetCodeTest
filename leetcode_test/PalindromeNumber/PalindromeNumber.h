#pragma once
/**
 * @brief     - ��������ȡ����ȡ���������Ҫ�����֣����� 1221 ������֣�
                ��� ���� 1221 / 1000�� ��ɵ���λ1�� ��� 1221 % 10�� 
                ��ɵõ�ĩβ1�����бȽϣ�Ȼ����м�� 22 ȡ�������Ƚ�
 * @param x  {int} ���������
 * @return   {bool}�ǻ����鷵��true�����򷵻�false
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
 * @brief     - �����ж�x�Ƿ�Ϊ���������������һ��С trick����Ϊ���������λ������0��
                ���Ի����������λҲ����Ϊ0������0���⣬�����������ĳ��������ĩβ��0�ˣ�
                Ҳֱ�ӷ��� false ���ɡ��ã�������������ⷨ��Ҫ��֤����������ô����Ҫ��ǰ�����Ƿ�Գƣ�
                ����Ѻ��η�תһ�£��Ϳ���ǰ����Ƿ���Ⱦ����ˡ�������������ȡ���������֣����з�ת��
                ���������ǣ�ÿ��ͨ���� 10 ȡ�࣬ȡ�����λ�����֣�Ȼ��ӵ�ȡ������ĩβ��
                ���ǽ� revertNum ���� 10���ټ������������������תҲ��ͬʱ����ˣ�ÿȡһ�����λ���֣�x��Ҫ�Գ��� 10��
                ������ revertNum ���ڵ���x��ʱ��ѭ��ֹͣ��
                ���ڻ�������λ�������ż�������ż���Ļ�����ô revertNum ��Ӧ�ú�x����ˣ�
                ����������Ļ�����ô���м�����־��� revertNum �����λ���ˣ����� 10 �Ժ�Ӧ�ú�x����ȵ�
 * @param x  {int} ���������
 * @return   {bool}�ǻ����鷵��true�����򷵻�false
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