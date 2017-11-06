function [] = plot_3R_robot( l1, l2, l3, theta_1, theta_2, theta_3, traj_t1, traj_t2, traj_t3, fig_handle )
    if nargin < 10
        fig_handle = figure;
    end
    
    x_A = l1*cos(theta_1);
    y_A = l1*sin(theta_1);
    x_B = l1*cos(theta_1) + l2*cos(theta_1+theta_2);
    y_B = l1*sin(theta_1) + l2*sin(theta_1+theta_2);
    x_P = l1*cos(theta_1) + l2*cos(theta_1+theta_2) + l3*cos(theta_1+theta_2+theta_3);
    y_P = l1*sin(theta_1) + l2*sin(theta_1+theta_2) + l3*sin(theta_1+theta_2+theta_3);
    
    traj_x = l1*cos(traj_t1) + l2*cos(traj_t1+traj_t2) + l3*cos(traj_t1+traj_t2+traj_t3);
    traj_y = l1*sin(traj_t1) + l2*sin(traj_t1+traj_t2) + l3*sin(traj_t1+traj_t2+traj_t3);

    figure(fig_handle);
    line([0 x_A], [0 y_A], 'Color', 'k', 'LineWidth', 1.5);
    hold on;
    plot(traj_x, traj_y, 'Color', 'b', 'LineWidth', 1.5);
    line([x_A x_B], [y_A y_B], 'Color', 'k', 'LineWidth', 1.5);
    line([x_B x_P], [y_B y_P], 'Color', 'k', 'LineWidth', 1.5);
    plot(0, 0, 'ko', 'LineWidth', 1.5);
    plot(x_A, y_A, 'ko', 'LineWidth', 1.5);
    plot(x_B, y_B, 'ko', 'LineWidth', 1.5);
    plot(x_P, y_P, 'ro', 'LineWidth', 1.5);
    axis equal;
    axis([-2.0 2.0 -2.0 2.0]);
    hold off;
end

