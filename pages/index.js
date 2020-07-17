// This thing is needed only because bs-emotion is not compatible with SSR
import dynamic from 'next/dynamic'

const DynamicApp = dynamic(() => import('./root.bs'), { ssr: false })

export default function App() {
  return <DynamicApp />
}