function plot_3R_movie(time_v, l1, l2, l3, theta_1, theta_2, theta_3, filename, total_real_time, width, height)            
    fps = 30;
    writerObj = VideoWriter(filename);
    %writerObj.Quality = 100;
    writerObj.open();

    plot_handle = figure('Position', [100, 100, width, height]);
    for i = 1:round(fps*total_real_time)
        t = round(length(time_v)/round(fps*total_real_time)*i);
        if t == 0
            t = 1;
        end
        
        plot_3R_robot( l1, l2, l3, theta_1(t), theta_2(t), theta_3(t), theta_1(1:t), theta_2(1:t), theta_3(1:t), plot_handle )
        
        frame = getframe(plot_handle);
        writerObj.writeVideo(frame);
        clf(plot_handle);
    end

    writerObj.close();
    close(plot_handle);
end