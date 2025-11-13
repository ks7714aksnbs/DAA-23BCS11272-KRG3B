import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpExchange;
import java.io.*;
import java.net.InetSocketAddress;

public class MainServer {
    public static void main(String[] args) throws IOException {
        HttpServer server = HttpServer.create(new InetSocketAddress(8080), 0);

        // Serve frontend files
        server.createContext("/", (exchange -> {
            String path = exchange.getRequestURI().getPath();
            if (path.equals("/")) path = "/index.html";
            File file = new File("." + path);
            if (!file.exists()) {
                exchange.sendResponseHeaders(404, -1);
                return;
            }
            byte[] bytes = java.nio.file.Files.readAllBytes(file.toPath());
            exchange.sendResponseHeaders(200, bytes.length);
            OutputStream os = exchange.getResponseBody();
            os.write(bytes);
            os.close();
        }));

        // Handle algorithm logic
        server.createContext("/calculate", (exchange -> {
            if ("POST".equals(exchange.getRequestMethod())) {
                BufferedReader reader = new BufferedReader(new InputStreamReader(exchange.getRequestBody()));
                String input = reader.readLine(); // e.g. "1,-2,3,4,-1,2,1,-5,4"
                String[] parts = input.split(",");
                int[] nums = new int[parts.length];
                for (int i = 0; i < parts.length; i++)
                    nums[i] = Integer.parseInt(parts[i].trim());

                int maxSum = kadane(nums);
                String response = "{\"maxSum\": " + maxSum + "}";
                exchange.getResponseHeaders().add("Content-Type", "application/json");
                exchange.sendResponseHeaders(200, response.getBytes().length);
                exchange.getResponseBody().write(response.getBytes());
                exchange.getResponseBody().close();
            }
        }));

        System.out.println("🚀 Server started at http://localhost:8080");
        server.start();
    }

    private static int kadane(int[] nums) {
        int maxSum = nums[0], currSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currSum = Math.max(nums[i], currSum + nums[i]);
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
    }
}
