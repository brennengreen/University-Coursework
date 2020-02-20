v_0 = 25;
y_0 = 3.5;
g = 9.81;

thetas = [30;45;60];
y1 = 0;
y2 = 0;
y3 = 0;

hold on
for theta_i = 1:length(thetas)
    theta = thetas(theta_i);
    d = ((v_0*cosd(theta))/g)*(v_0*sind(theta) + sqrt((v_0*sind(theta))^2 + 2*g*y_0));
    

    
    displacement = linspace(0, d, 200)';
    y_list = linspace(0,200)';
    for i = 1:length(displacement)
        x = displacement(i);
        y = x*tand(theta)-(0.5)*(((x^2)*g)/((v_0*cosd(theta))^2)) + y_0;
        y_list(i) = y;
    end
    
    if (theta_i == 1)
        y1 = y_list;
    elseif (theta_i == 2)
        y2 = y_list;
    elseif (theta_i == 3)
        y3 = y_list;
    end
    
    
    plot(displacement, y_list);
end