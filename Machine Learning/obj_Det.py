import cv2
import numpy as np

#1 is for iriun webcam nad 0 is for laptop webcam
cap = cv2.VideoCapture(1)
whT = 320
confThreshold = 0.5
nmsThreshold = 0.3
classFile='coco.names'
classNames = []

with open(classFile, 'rt') as f:
    classNames = f.read().rstrip('\n').split('\n')

#print(classNames)

modelConfiguration = 'yolov3.cfg'
modelWeights = 'yolov3.weights'

#create our network
net = cv2.dnn.readNetFromDarknet(modelConfiguration, modelWeights)
net.setPreferableBackend(cv2.dnn.DNN_BACKEND_OPENCV)
net.setPreferableTarget(cv2.dnn.DNN_TARGET_CPU)

#netwrork accept a particular type of format called blob

def  findObjects(outputs,img):
    hT,wT,cT = img.shape
    bbox = []
    classIds = []
    confs = []

    for output in outputs:
        for det in output:
            scores = det[5:]
            classId = np.argmax(scores)
            confidence = scores[classId]
            if confidence > confThreshold:
                w,h = int(det[2]*wT), int(det[3]*hT)
                x,y = int((det[0]*wT)-w/2), int((det[1]*hT) - h/2)
                bbox.append([x,y,w,h])
                classIds.append(classId)
                confs.append(float(confidence))

    #print(bbox)
    indices = cv2.dnn.NMSBoxes(bbox, confs, confThreshold, nmsThreshold)
    for i in indices:
        i = i[0]
        box=bbox[i]
        x,y,w,h = box[0], box[1], box[2], box[3]
        cv2.rectangle(img, (x,y),(x+w,y+h), (255,0,255),2)
        cv2.putText(img, f'{classNames[classIds[i]].upper()} {int(confs[i]*100)}%', (x,y-10), cv2.FONT_HERSHEY_COMPLEX_SMALL, 0.6, (255,0,255), 2)

while True:
    success, img = cap.read()
    #convert image in blob
    blob = cv2.dnn.blobFromImage(img,1/255,(whT,whT),[0,0,0],1,crop=False)
    net.setInput(blob)

    layerNames = net.getLayerNames()
    #print(layerNames)

    #get only 3 output layers
    outputNames = [layerNames[i[0]-1] for i in net.getUnconnectedOutLayers()]
    #print(outputNames)

    outputs = net.forward(outputNames)

    # print(outputs[0].shape)
    findObjects(outputs, img)
    cv2.imshow('Image', img)
    cv2.waitKey(1)