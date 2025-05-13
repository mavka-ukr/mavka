for i in {1..100} ; do
  for x in {1..100} ; do
    nc localhost 8080 &
  done
  echo "$i"
done