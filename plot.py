import matplotlib.pyplot as plt

# Reading data from a file called "output_file"
processors = []
bdcast_times = []
send_recv_times = []

with open("output_file", "r") as file:
    for line in file:
        parts = line.split()
        processors.append(int(parts[0]))
        bdcast_times.append(float(parts[2]))
        send_recv_times.append(float(parts[3]))

# Convert times to human-readable format (milliseconds)
bdcast_times_ms = [t * 1000 for t in bdcast_times]
send_recv_times_ms = [t * 1000 for t in send_recv_times]

# Both x and y axes logarithmic
plt.figure(figsize=(10, 6))
plt.plot(processors, bdcast_times_ms, label="MPI_Bcast (Collective)", marker="o")
plt.plot(processors, send_recv_times_ms, label="Send/Recv (Point-to-Point)", marker="s")

plt.xscale("log")
plt.yscale("log")
plt.xticks(processors, labels=processors)  # Show actual processor numbers on the x-axis
plt.xlabel("Number of Processors")
plt.ylabel("Execution Time (milliseconds)")
plt.title("Execution Time vs Number of Processors (Log-Log Scale)")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.tight_layout()
plt.savefig("log_log_graph_from_file_with_actual_proc.png")  # Save the graph
plt.close()

# Both x and y axes linear
plt.figure(figsize=(10, 6))
plt.plot(processors, bdcast_times_ms, label="MPI_Bcast (Collective)", marker="o")
plt.plot(processors, send_recv_times_ms, label="Send/Recv (Point-to-Point)", marker="s")

plt.xlabel("Number of Processors")
plt.ylabel("Execution Time (milliseconds)")
plt.title("Execution Time vs Number of Processors (Linear-Linear Scale)")
plt.legend()
plt.grid(True, linestyle="--", linewidth=0.5)
plt.tight_layout()
plt.savefig("linear_linear_graph_from_file.png")  # Save the graph
plt.close()

print("Graphs saved as 'log_log_graph_from_file_with_actual_proc.png' and 'linear_linear_graph_from_file.png'.")
