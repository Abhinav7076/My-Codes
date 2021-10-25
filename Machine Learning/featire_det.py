import  cv2
import numpy as np

#grab images  ',0' will import image as grayscale
img1 = cv2.imread('ImagesGallery/GTA V.jpeg',0)
img2 = cv2.imread('ImagesTrain/GTA V Train.jpeg',0)


#create detector : orb '(oriented fast and rotated)
#idea : find features find descriptors which will help us to identify the image

#initialize detector
orb = cv2.ORB_create(nfeatures=1000)

#keypoints and decriptors 500 features decribed in 32 values
kp1, des1 = orb.detectAndCompute(img1, None)
kp2, des2 = orb.detectAndCompute(img2, None)

#now we can use ma matcher to match these descriptors to get how much similarity is there
#we'll use knn


bf = cv2.BFMatcher()  # brute force matcher
matches = bf.knnMatch(des1,des2,k=2)

good = []
for m,n in matches:
    if m.distance < 0.75*n.distance:
        good.append([m])
print(len(good))
img3 = cv2.drawMatchesKnn(img1,kp1,img2,kp2,good,None,flags=2)

imgkp1 = cv2.drawKeypoints(img1, kp1, None)
imgkp2 = cv2.drawKeypoints(img2, kp2, None)


cv2.imshow('img1',imgkp1)
cv2.imshow('img2',imgkp2)
cv2.imshow('img3',img3)
cv2.waitKey(0)