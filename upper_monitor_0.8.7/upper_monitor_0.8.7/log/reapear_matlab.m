clear;
clc;
close all;

rand1 = [0.1078    0.0229    0.0318    0.9986    0.9962    0.9176    0.0032    0.6120    0.7067    0.1662    0.1704    0.0740    0.9828    0.1544    0.7581    0.6855    0.8324    0.2992    0.3596    0.4243];
rand2 = [0.1231    0.0312    0.9265    0.0420    0.0175    0.7510    0.9557    0.6073    0.5578    0.6225    0.2578    0.6841    0.4022    0.3813    0.8711    0.2941    0.5975    0.4526    0.5583    0.4294];
rand3 = [0.2556    0.9088    0.0343    0.9683    0.0164    0.8929    0.9844    0.1138    0.3134    0.9879    0.3968    0.4024    0.6207    0.1611    0.3508    0.5306    0.3353    0.4226    0.7425    0.1249];

filename = input('Please input filename of log:', 's');
fid = fopen(filename, 'r');
if fid == -1
    disp('File open failed!');
    return;
else
    fclose(fid);
    temp = importdata(filename);
    datasize = size(temp.data);
    data_account = datasize(1);
    agent_account = datasize(2)/3;
    
    marker = ['o', '*', '<', '+', 'd', 'x', 'p', 'h', '.', 'v', '>', '^'];
    for i=1:20
         color_r(1, i) = rand1(1, i);
         color_g(1, i) = rand2(1,i);
         color_b(1, i) = rand3(1,i);
    end

    
 
    for i=1:data_account
        % 经度-纬度-高度图
        figure(1); 
        for j=1:agent_account
            h(j) = plot3(temp.data(1:i, (j-1)*3+1), temp.data(1:i, (j-1)*3+2), temp.data(1:i, (j-1)*3+3), '-', 'LineWidth', 2.0, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);    
            hold on;
            plot3(temp.data(i, (j-1)*3+1), temp.data(i, (j-1)*3+2), temp.data(i, (j-1)*3+3), '.', 'MarkerSize', 15, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);
            %axis([temp.data(1,1)-0.0002, temp.data(1,1)+0.0001, temp.data(1,2)-0.0002, temp.data(1,2)+0.0001, 0, temp.data(1,3)+5]); 
            axis([113.38315, 113.38345, 23.06635, 23.06665, 2, 12]); 
            xlabel('longitude');
            ylabel('latitude');
            zlabel('altitude');
%             xlabel('x');
%             ylabel('y');
%             zlabel('z');
            title('Formation flight of multiple UAVs');
            set(gca,'Fontsize',15)
            hold on;
            
            for k=1:agent_account
                plot3(temp.data(1, (k-1)*3+1), temp.data(1, (k-1)*3+2), temp.data(1, (k-1)*3+3), '^', 'MarkerSize', 5, 'Color', [color_r(1, k), color_g(1, k),color_b(1, k)]);
                hold on;       
            end   
        end
        legend(h(1:agent_account),'UAV1', 'UAV2', 'UAV3', 'UAV4','UAV5', 'UAV6', 'UAV7', 'UAV8', 'Location', 'BestOutside');
        hold off;
        pause(0.00001);
        
        % 经度-纬度图
        figure(2); 
        for j=1:agent_account
            h(j) = plot(temp.data(1:i, (j-1)*3+1), temp.data(1:i, (j-1)*3+2), '-','LineWidth', 2.0, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);
            hold on;
            plot(temp.data(i, (j-1)*3+1), temp.data(i, (j-1)*3+2), '.', 'MarkerSize', 15, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);
            %axis([temp.data(1,1)-0.0002, temp.data(1,1)+0.0001, temp.data(1,2)-0.0002, temp.data(1,2)+0.0001, 0, temp.data(1,3)+5]); 
            %axis([-1, 11, -1, 11, -3, 3]); 
            axis([113.38315, 113.38345, 23.06635, 23.06665]); 
            xlabel('longitude');
            ylabel('latitude');
%             xlabel('x');
%             ylabel('y');
            title('Formation flight of multiple UAVs');
            set(gca,'Fontsize',15)
            hold on;
            for k=1:agent_account
                plot(temp.data(1, (k-1)*3+1), temp.data(1, (k-1)*3+2), '^', 'MarkerSize', 5, 'Color', [color_r(1, k), color_g(1, k),color_b(1, k)]);
                hold on;       
            end   
        end
        
        legend(h(1:agent_account),'UAV1', 'UAV2', 'UAV3', 'UAV4','UAV5', 'UAV6', 'UAV7', 'UAV8', 'Location', 'BestOutside');
        hold off;
        pause(0.00001);      
        
        % 经度-高度图
        figure(3); 
        for j=1:agent_account
            h(j)=plot(temp.data(1:i, (j-1)*3+1), temp.data(1:i, (j-1)*3+3), '-','LineWidth', 2.0, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);
            hold on;
            plot(temp.data(i, (j-1)*3+1), temp.data(i, (j-1)*3+3), '.', 'MarkerSize', 15, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);
            %axis([temp.data(1,1)-0.0002, temp.data(1,1)+0.0001, temp.data(1,2)-0.0002, temp.data(1,2)+0.0001, 0, temp.data(1,3)+5]); 
            %axis([-1, 11, -1, 11, -3, 3]); 
            axis([113.38315, 113.38345, 2, 12]); 
            xlabel('longitude');
            ylabel('altitude');
%             xlabel('x');
%             ylabel('z');
            title('Formation flight of multiple UAVs');
            set(gca,'Fontsize',15)
            hold on;
            
            for k=1:agent_account
                plot(temp.data(1, (k-1)*3+1), temp.data(1, (k-1)*3+3), '^', 'MarkerSize', 5, 'Color', [color_r(1, k), color_g(1, k),color_b(1, k)]);
                hold on;       
            end   
        end
        legend(h(1:agent_account),'UAV1', 'UAV2', 'UAV3', 'UAV4','UAV5', 'UAV6', 'UAV7', 'UAV8', 'Location', 'BestOutside');
        hold off;
        pause(0.00001);

        % 纬度-高度图
        figure(4); 
        for j=1:agent_account
            h(j)=plot(temp.data(1:i, (j-1)*3+2), temp.data(1:i, (j-1)*3+3), '-','LineWidth', 2.0, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);
            hold on;
            plot(temp.data(i, (j-1)*3+2), temp.data(i, (j-1)*3+3), '.', 'MarkerSize', 15, 'Color', [color_r(1, j), color_g(1, j),color_b(1, j)]);
            %axis([temp.data(1,1)-0.0002, temp.data(1,1)+0.0001, temp.data(1,2)-0.0002, temp.data(1,2)+0.0001, 0, temp.data(1,3)+5]); 
            %axis([-1, 11, -1, 11, -3, 3]); 
            axis([23.06635, 23.06665, 2, 12]);
            xlabel('latitude');
            ylabel('altitude');
%             xlabel('y');
%             ylabel('z');
            title('Formation flight of multiple UAVs');
            set(gca,'Fontsize',15)
            hold on;
            
            for k=1:agent_account
                plot(temp.data(1, (k-1)*3+2), temp.data(1, (k-1)*3+3), '^', 'MarkerSize', 5, 'Color', [color_r(1, k), color_g(1, k),color_b(1, k)]);
                hold on;       
            end   
        end
        legend(h(1:agent_account),'UAV1', 'UAV2', 'UAV3', 'UAV4','UAV5', 'UAV6', 'UAV7', 'UAV8', 'Location', 'BestOutside');
        hold off;
        pause(0.00001);
    end
end