#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  int count1 = 0,count2 = 0,count3 = 0;
  for(int i=0;i<nBatteries;i++)
  {
    if(cycles[i] < 410)
    {
      counts1 += 1;
    }
    else if(cycles[i] >= 410 && cycles[i] <= 909)
    {
      count2 += 1;
    }
    else
    {
      count3 += 1;
    }
  }
  counts = {count1,count2,count3};
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == count1);//2
  assert(counts.mediumCount == count2);//3
  assert(counts.highCount == count3);//1
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
