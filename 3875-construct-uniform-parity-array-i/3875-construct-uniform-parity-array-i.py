class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        nums2=[]
        nums3=[]
        pe=0
        po=0
        for ch in nums1:
            if(ch%2 ==0):
                pe=ch
            else:
                po=ch
        if po == pe:
            return False
        else:
            return True
        for ch in nums1:
            if(ch%2 ==0):
                nums2.append(ch)
                continue
            else:
                nums1.append(ch)
                continue