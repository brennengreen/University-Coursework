clear;

cam = webcam(2);
cam.Resolution = '640x480';
preview(cam)

pause(10)

closePreview(cam)
img = snapshot(cam);
imshow(img);