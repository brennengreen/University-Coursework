% Create a program to plot the motion of the ping pong ball with drag. 
% The program will take inputs for velocity in m/s and angle of launch.
% note that with a high speed camera I estmated a launch speed for a ping
% pong ball could be 30 m/s.  

angle = 20:5:80;
angle = angle*pi/180;
rangeAngle=length(angle);
velStart = input('Input velocity in m/s: ');

hold on
for i=1:rangeAngle
    % set initial position and time
    x=[];
    y=[];
    time=[];
    vel=velStart;
    VelocityX=[];
    VelocityY=[];
    x(1)=0; % meters
    y(1)=.01;  % meters
    time(1)=0; % seconds
    mass=.00247; %kg  ping pong ball .00247 Kg
    g=-9.8; % m/sec^2
    c=-0.0005; % coefficient of drag where Re is between 10^3 and 10^5
     % so I can load an array for plotting
    % start to increment the motion

    index=1; % so I can load an array for plotting
    thisAngle=angle(i);
    velx=vel*cos(thisAngle);
    VelocityX(1)=velx;
    vely=vel*sin(thisAngle);
    VelocityY(1)=vely;
    % set a time step
    deltaTime=.001; % seconds
    height=y(1);
    flag=0;




    while height>=0 % check that the ball has not hit ground yet 
        index=index+1; % setup and index

        % *******************************************************
        % break velocity into its components
        % *******************************************************
        velx = vel*cos(thisAngle);
        vely = vel*sin(thisAngle);

        % *******************************************************
        % use an if/else statement to check to see if the ball is moving 
        % down (negative). If it is, then drag has an opposite sign
        % as gravity in the acceleration formula.  Otherwise gravity
        % and drag have the same sign. Calculate the new acceleration in the y.
        % *******************************************************
        if (vely < 0)
           acc_y = g + ((-c*(vely*vely))/mass);
        else
           acc_y = g + ((c*(vely*vely))/mass);
        end
        % *******************************************************
        % Now calculate the acceleration in the x .
        % *******************************************************
        acc_x = (c * (velx*velx))/mass;
        % *****************************************************
        % calculate the new velocity at the end of the time step
        % this will have X and Y components, so you need a variable
        % for each.  One is velFinalX and the other is velFinalY.
        % *******************************************************
        velFinalX = velx + acc_x*deltaTime;
        velFinalY = vely + acc_y*deltaTime;

        % ******************************************************
        % Get a new velocity vector and angle given the X and Y
        % The velocity is the variable "vel" and angle is "thisAngle"
        %*******************************************************
        vel = sqrt(velFinalX*velFinalX + velFinalY*velFinalY);
        thisAngle = atan(velFinalY/velFinalX);

        % now save my values at this time step
        time(index)=time(index-1)+deltaTime;
        VelocityX(index)=velFinalX;
        VelocityY(index)=velFinalY;

        % and distance numbers
        distX=velx*deltaTime;
        distY=vely*deltaTime;

        % save distance values 
        x(index)=x(index-1)+distX;
        y(index)=y(index-1)+distY;
        height=y(index);

        if distY < 0 && flag <=1
            if height < .25
                disp(distY)
                fprintf('goal height detected at distance %.2f meters.', x(index));
                flag = 2;
                LandingDistance(i)=x(index);
            end
        end
    end

    outputArray = [x;y];
    outputArray = outputArray';

    plot(x,y)
    title('distance traveled by ping pong ball in meters')
    xlabel('horixontal distance traveled (meters)')
    ylabel('vertical distance traveled (meters)')
end
hold off


figure
angleDeg = (angle.*180)./pi;
plot(angleDeg, LandingDistance);
title('Distance to goal at goal height');
xlabel('Angle of initial launch');
ylabel('Distance from launcher when passing goal height');