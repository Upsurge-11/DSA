def main():
  folder = [x for x in input().split()]
  print(removeSubfolders(folder))

def removeSubfolders(folder: list[str]) -> list[str]:
  folder.sort()
  ans = [folder[0]]
  for i in range(1, len(folder)):
    last_folder = ans[-1] + '/'
    if not folder[i].startswith(last_folder):
      ans.append(folder[i])
  return ans

if __name__ == '__main__':
  main()