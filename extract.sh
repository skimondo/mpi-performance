rm output_file
for file in stdout_*.out; do
    tail -n 2 "$file" | head -n 1 >> output_file
done

